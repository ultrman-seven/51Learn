#ifndef F14B5884_5F28_43E1_A7D5_B1EF8011706E
#define F14B5884_5F28_43E1_A7D5_B1EF8011706E
#include "stcint.h"
#include "wy_chipHeader.h"
#include "INTRINS.H"
#ifndef __VS_CODE_
#define def_s_bit(_r, _bit) ((_r) ^ (_bit))
#define IRQ_Num(n) interrupt n
#else
#define def_s_bit(_r, _bit) (0)
#define IRQ_Num(n)
#endif

// 系统时钟
#define SYS_CLK_FREQ (11059200)
#define SYS_CLK_FREQ_MHz (11.0592)

// #define SYS_CLK_FREQ (12000000)
// #define SYS_CLK_FREQ_MHz (12)

// #define SYS_CLK_FREQ (22118400)
// #define SYS_CLK_FREQ_MHz (22.1184)

// #define SYS_CLK_FREQ (24000000)
// #define SYS_CLK_FREQ_MHz (24)

// #define SYS_CLK_FREQ (30000000)
// #define SYS_CLK_FREQ_MHz (30)

// #define SYS_CLK_FREQ (33000000)
// #define SYS_CLK_FREQ_MHz (33)

// #define SYS_CLK_FREQ (33177600)
// #define SYS_CLK_FREQ_MHz (33.1776)


// 指令集
#define ISA_STC_Y1 0
#define ISA_STC_Y3 1
#define ISA_STC_Y5 2
#define ISA_STC_Y6 3

#ifndef SYS_ISA
#define SYS_ISA ISA_STC_Y1
#endif

#define Enable 1
#define Disable 0

#define chiefInterruptConfig(__nvic_state) EA = __nvic_state

void delayMs(uint16_t time);
void delay(uint16_t time);
#endif /* F14B5884_5F28_43E1_A7D5_B1EF8011706E */
