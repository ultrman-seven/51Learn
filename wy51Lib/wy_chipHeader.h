#ifndef __WY_CHIP_HEAD_H__
#define __WY_CHIP_HEAD_H__

#ifdef __CHIP_STC_89C51_
#include "reg51.h"
#define SYS_ISA ISA_STC_Y1
#elif defined __CHIP_STC_89C52_
#define SYS_ISA ISA_STC_Y1
#include "reg52.h"
#elif defined __CHIP_STC_90C_
#define SYS_ISA ISA_STC_Y1
#include "STC90C5xAD.H"
#elif defined __CHIP_STC_8A_
#define SYS_ISA ISA_STC_Y6
#include "STC8A8K64D4.H"
#elif defined __CHIP_STC_8H_
#define SYS_ISA ISA_STC_Y6
#include "STC8H.H"
#elif defined __CHIP_STC_8F_
#define SYS_ISA ISA_STC_Y6
#include "STC8F.H"
#elif defined __CHIP_STC_8G_
#define SYS_ISA ISA_STC_Y6
#include "STC8G.H"
#else
#include "reg51.h"
#define SYS_ISA ISA_STC_Y1
#endif

#endif /* __WY_CHIP_HEAD_H__ */
