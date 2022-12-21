#include "wy_exti.h"
#define HAVE_INT2_3 (!((defined __REG51_H__) || (defined __REG52_H__)))

void (*int0IRQCbkFunc)(void);
void (*int1IRQCbkFunc)(void);
#if HAVE_INT2_3
void (*int2IRQCbkFunc)(void);
void (*int3IRQCbkFunc)(void);
#endif

void externalInterruptConfig(uint8_t extiNum, EXIT_mode mode, void (*callback)(void))
{
    switch (extiNum)
    {
    case 0:
        EX0 = 1;
        IT0 = mode;
        int0IRQCbkFunc = callback;
        break;
    case 1:
        EX1 = 1;
        IT1 = mode;
        int1IRQCbkFunc = callback;
        break;
#if HAVE_INT2_3
    case 2:
        EX2 = 1;
        IT2 = mode;
        int2IRQCbkFunc = callback;
        break;
    case 3:
        EX3 = 1;
        IT3 = mode;
        int3IRQCbkFunc = callback;
        break;
#endif
    default:
        break;
    }
}

void int0IRQ_Handler(void) IRQ_Num(0)
{
    int0IRQCbkFunc();
}
void int1IRQ_Handler(void) IRQ_Num(2)
{
    int1IRQCbkFunc();
}
#if HAVE_INT2_3
void int2IRQ_Handler(void) IRQ_Num(6)
{
    int2IRQCbkFunc();
}
void int3IRQ_Handler(void) IRQ_Num(7)
{
    int3IRQCbkFunc();
}
#endif
