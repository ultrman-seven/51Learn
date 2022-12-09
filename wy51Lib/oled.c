#include "spi.h"

sbit oled_dc;
sbit oled_rst;

#define OLED_HAS_CS

#ifdef OLED_HAS_CS
sbit oled_cs;
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
