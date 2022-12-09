#include "spi.h"

sbit spi_sck;
sbit spi_mosi;
sbit spi_miso;

#ifdef SPI_CPOL_LOW
#define SPI_CPOL_BUSY (0)
#define SPI_CPOL_FREE (1)
#elif defined SPI_CPOL_HIGH
#define SPI_CPOL_BUSY (1)
#define SPI_CPOL_FREE (0)
#endif

void SPI_Init(void)
{
    spi_sck = SPI_CPOL_FREE;
}

void SPI_SendByte(uint8_t dat)
{
    uint8_t cnt = 8;
    while (cnt--)
    {
#ifdef SPI_CPHA_1Edge
        spi_mosi = dat & 0x80;
        _nop_();
        spi_sck = SPI_CPOL_BUSY;
        _nop_();
        spi_sck = SPI_CPOL_FREE;
#else
        spi_sck = SPI_CPOL_BUSY;
        spi_mosi = dat & 0x80;
        _nop_();
        spi_sck = SPI_CPOL_FREE;
        _nop_();
#endif
        dat <<= 1;
    }
}

uint8_t SPI_ReadByte(void)
{
    uint8_t result = 0, cnt = 8;

    while (cnt--)
    {
        result <<= 1;
#ifdef SPI_CPHA_1Edge
        spi_sck = SPI_CPOL_BUSY;
        _nop_();
        result += spi_miso;
        spi_sck = SPI_CPOL_FREE;
        _nop_();
#else
        spi_sck = SPI_CPOL_BUSY;
        _nop_();
        spi_sck = SPI_CPOL_FREE;
        _nop_();
        result += spi_miso;
#endif
    }
}

uint8_t SPI_WriteReadByte(uint8_t dat)
{
    uint8_t result = 0, cnt = 8;

    while (cnt--)
    {
        result <<= 1;
#ifdef SPI_CPHA_1Edge
        spi_mosi = dat & 0x80;
        _nop_();
        spi_sck = SPI_CPOL_BUSY;
        _nop_();
        result += spi_miso;
        spi_sck = SPI_CPOL_FREE;
#else
        spi_sck = SPI_CPOL_BUSY;
        _nop_();
        spi_mosi = dat & 0x80;
        spi_sck = SPI_CPOL_FREE;
        _nop_();
        result += spi_miso;
#endif
        dat <<= 1;
    }
}
