#ifndef D9C5BA09_4952_4306_87C1_59C15E97CCF2
#define D9C5BA09_4952_4306_87C1_59C15E97CCF2

#include "reg51.h"
#include "common.h"

#define SPI_CPOL_LOW
// #define SPI_CPOL_HIGH

// #define SPI_CPHA_1Edge
void SPI_Init(void);
void SPI_SendByte(uint8_t dat);
uint8_t SPI_ReadByte(void);
uint8_t SPI_WriteReadByte(uint8_t dat);

#endif /* D9C5BA09_4952_4306_87C1_59C15E97CCF2 */
