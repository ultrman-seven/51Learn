#ifndef _WY_51_LIB_OLED_H__
#define _WY_51_LIB_OLED_H__
#include "stcint.h"
#define OLED_HAS_CS
// #define OLED_NO_CS

void OLED_putchar(char c);
void OLED_print(char *s);
void OLED_putNumber(int32_t num);
void OLED_clear(void);

void OLED_Init(void);
void OLED_displayPicture(uint8_t *img, uint8_t pageStart, uint8_t colStart, uint8_t imgWidth, uint8_t imgHeight);
#endif /* _WY_51_LIB */_STC_INT__
