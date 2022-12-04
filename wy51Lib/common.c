#include "common.h"

void delayMs(uint16_t time)
{
    uint16_t freqMhz = time * SYS_CLK_FREQ_MHz;

    unsigned char i;
#if (SYS_ISA != ISA_STC_Y1)
    unsigned char j;
#endif
    while (freqMhz--)
    {
#if (SYS_ISA == ISA_STC_Y1)
        i = 39;
        while (--i)
            ;
#elif (SYS_ISA == ISA_STC_Y3)
        _nop_();
        _nop_();
        i = 1;
        j = 244;
        do
        {
            while (--j)
                ;
        } while (--i);
#elif (SYS_ISA == ISA_STC_Y5)
        i = 1;
        j = 245;
        do
        {
            while (--j)
                ;
        } while (--i);
#elif (SYS_ISA == ISA_STC_Y6)
        _nop_();
        i = 2;
        j = 72;
        do
        {
            while (--j)
                ;
        } while (--i);
#endif
    }
}
