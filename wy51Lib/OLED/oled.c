#include "spi.h"
#include "oled.h"

#include "font.h"

#define CALL_BELL

sbit oled_dc = def_s_bit(P0, 3);
sbit oled_rst = def_s_bit(P0, 2);

#ifdef OLED_HAS_CS
sbit oled_cs = def_s_bit(P0, 4);
#define OLED_CS_CHOSEN oled_cs = 0
#define OLED_CS_ABANDON oled_cs = 1
#else
#define OLED_CS_CHOSEN
#define OLED_CS_ABANDON
#endif

void OLED_SendCMD(uint8_t cmd)
{
    OLED_CS_CHOSEN;
    oled_dc = 0;
    SPI_SendByte(cmd);
    OLED_CS_ABANDON;
}
void OLED_SendData(uint8_t cmd)
{
    OLED_CS_CHOSEN;
    oled_dc = 1;
    SPI_SendByte(cmd);
    OLED_CS_ABANDON;
}

void setCol(uint8_t c)
{
    uint8_t cmd;

    cmd = 0x10 | ((c >> 4) & 0x0f);
    OLED_SendCMD(cmd);

    cmd = 0x00 | (c & 0x0f);
    OLED_SendCMD(cmd);
}

void setPage(uint8_t p)
{
    OLED_SendCMD(0xb0 | p);
}

uint8_t currentPage = 0;
uint8_t currentCol = 0;
#define OLED_Width 128
void OLED_putchar(char c)
{
    switch (c)
    {
    case '\n':
        goto newLine;
        break;
    case '\b':
        if (currentCol)
        {
            OLED_displayPicture(ASCII[0], currentPage, currentCol - 8, AsciiWidth, AsciiHeight);
            currentCol -= 8;
        }
        else if (currentPage)
        {
            OLED_displayPicture(ASCII[0], currentPage - 2, OLED_Width - 8, AsciiWidth, AsciiHeight);
            currentPage -= 2;
            currentCol = OLED_Width - 8;
        }
        break;
    case 127:
        break;
    case '\t':
        OLED_putchar(' ');
        OLED_putchar(' ');
        break;
    case '\a':
        CALL_BELL;
        break;
    default:
        OLED_displayPicture(ASCII[c - ' '], currentPage, currentCol, AsciiWidth, AsciiHeight);
        currentCol += 8;
        break;
    }

    if (currentCol >= OLED_Width)
    {
    newLine:
        currentCol = 0;
        if (currentPage < 6)
            currentPage += 2;
        else
            OLED_clear();
    }
}

void OLED_clear(void)
{
    uint8_t totalPage = 8;
    uint8_t colCnt;
    while (totalPage--)
    {
        colCnt = OLED_Width;
        setPage(totalPage);
        setCol(0);
        while (colCnt--)
            OLED_SendData(0x00);
    }
    currentCol = currentPage = 0;
}
void OLED_print(char *s)
{
    while (*s)
        OLED_putchar(*s++);
}

void OLED_putNumber(int32_t num)
{
    if (num < 0)
    {
        OLED_putchar('-');
        num = -num;
    }

    //
}

// code 是 C51 关键字
// https://blog.csdn.net/m0_46559794/article/details/108006698
code uint8_t rstCmd[] = {0xae, 0x00, 0x10, 0x40, 0x81,
                         0x7f, 0xa1, 0xc8, 0xa6, 0xa8, 0x3f, 0xd3,
                         0x00, 0xd5, 0x80, 0xd9, 0xf1, 0xda, 0x12, 0xdb,
                         0x40, 0x20, 0x02, 0x8d, 0x14, 0xa4, 0xa6, 0xaf};
#define rstCMD_Len 28

void OLED_Init(void)
{
    uint8_t cnt = 0;
    SPI_Init();
    oled_rst = 0;
    delayMs(100);
    oled_rst = 1;
    while (cnt < 28)
        OLED_SendCMD(rstCmd[cnt++]);
    OLED_clear();
}

void OLED_displayPicture(uint8_t *img, uint8_t pageStart, uint8_t colStart, uint8_t imgWidth, uint8_t imgHeight)
{
    uint8_t totalPage = imgHeight / 8;
    uint8_t pageCnt = 0;
    uint8_t colCnt;
    while (totalPage--)
    {
        setPage(pageStart + pageCnt++);

        setCol(colStart);

        colCnt = imgWidth;
        while (colCnt--)
            OLED_SendData(*img++);
    }
}
