#include "spi.h"

sbit spi_sck = def_s_bit(P0, 0);
sbit spi_mosi = def_s_bit(P0, 1);
sbit spi_miso = def_s_bit(P1, 0);

#ifdef SPI_CPOL_LOW
#define _SPI_CPOL_BUSY (1)
#define _SPI_CPOL_FREE (0)
// #elif defined SPI_CPOL_HIGH
#else
#define _SPI_CPOL_BUSY (0)
#define _SPI_CPOL_FREE (1)
#endif

#ifdef SPI_FirstBit_High2Low
#define _SPI_DATA_MASK (0x80)
#define _SPI_DATA_Shift(__d) (__d <<= 1)
// #elif defined SPI_FirstBit_Low2High
#else
#define _SPI_DATA_MASK (0x01)
#define _SPI_DATA_Shift(__d) (__d >>= 1)
#endif

void SPI_Init(void)
{
        spi_sck = _SPI_CPOL_FREE;
}

void SPI_SendByte(uint8_t dat)
{
        uint8_t cnt = 8;
        while (cnt--)
        {
#ifdef SPI_CPHA_1Edge
                spi_mosi = dat & _SPI_DATA_MASK;
                _nop_();
                spi_sck = _SPI_CPOL_BUSY;
                _nop_();
                spi_sck = _SPI_CPOL_FREE;
#else
                spi_sck = _SPI_CPOL_BUSY;
                spi_mosi = dat & _SPI_DATA_MASK;
                _nop_();
                spi_sck = _SPI_CPOL_FREE;
                _nop_();
#endif
                _SPI_DATA_Shift(dat);
        }
}

uint8_t SPI_ReadByte(void)
{
        uint8_t result = 0, cnt = 8;

        while (cnt--)
        {
                _SPI_DATA_Shift(result);
#ifdef SPI_CPHA_1Edge
                spi_sck = _SPI_CPOL_BUSY;
                _nop_();
                result |= spi_miso;
                spi_sck = _SPI_CPOL_FREE;
                _nop_();
#else
                spi_sck = _SPI_CPOL_BUSY;
                _nop_();
                spi_sck = _SPI_CPOL_FREE;
                _nop_();
                result |= spi_miso;
#endif
        }
        return result;
}

uint8_t SPI_WriteReadByte(uint8_t dat)
{
        uint8_t result = 0, cnt = 8;

        while (cnt--)
        {
                _SPI_DATA_Shift(result);
#ifdef SPI_CPHA_1Edge
                spi_mosi = dat & _SPI_DATA_MASK;
                _nop_();
                spi_sck = _SPI_CPOL_BUSY;
                _nop_();
                result |= spi_miso;
                spi_sck = _SPI_CPOL_FREE;
#else
                spi_sck = _SPI_CPOL_BUSY;
                _nop_();
                spi_mosi = dat & _SPI_DATA_MASK;
                spi_sck = _SPI_CPOL_FREE;
                _nop_();
                result |= spi_miso;
#endif
                _SPI_DATA_Shift(dat);
        }
        return result;
}
