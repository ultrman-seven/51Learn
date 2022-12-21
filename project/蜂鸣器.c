#include "common.h"

// #include "reg51.h"

sbit beep = def_s_bit(P2, 5);

#define BEEP_DELAY_HIGH_TIME 200

#define BEEP_DELAY_LOW_TIME 300

void beepRunByLoop(uint16_t cycles)
{
    while (cycles--)
    {
        beep = 0;
        delay(BEEP_DELAY_HIGH_TIME);
        beep = 1;
        delay(BEEP_DELAY_LOW_TIME);
    }
}

void beepRunByTimIRQ(void)
{

}
