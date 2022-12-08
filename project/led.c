#include "stcint.h"
#include "INTRINS.H"

sfr P2 = 0xa0;

void delay(uint16_t time)
{
    while (time--)
    {
        uint16_t tmp = 0xff;
        while (tmp--)
            ;
    }
}
void Delay100us() //@12.000MHz
{
    unsigned char i;

    _nop_();
    i = 47;
    while (--i)
        ;
}
void Delay_ms(uint16_t time) //@12.000MHz
{
    unsigned char i, j;
    while (time--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}
int main()
{
    P2 = 0xfe;
    while (1)
    {
        P2 <<= 1;
        P2 |= 0x01;
        if (P2 == 0xff)
            P2 = 0xfe;
        Delay_ms(1000);
    }
}
