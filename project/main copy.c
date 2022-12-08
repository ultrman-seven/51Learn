#include "common.h"
#include "reg51.h"

sbit DS1302CS = def_s_bit(P3, 5);
sbit DS1302Dat = def_s_bit(P3, 4);
sbit DS1302Sck = def_s_bit(P3, 6);

void DS1302SendByte(uint8_t dat)
{
    uint8_t cnt = 8;
    DS1302CS = 1;

    DS1302Sck = 0;
    while (cnt--)
    {
        DS1302Dat = dat & 0x01;

        _nop_();
        DS1302Sck = 1;
        _nop_();
        DS1302Sck = 0;

        dat >>= 1;
    }

    DS1302CS = 0;
}
uint8_t DS1302ReadByte(void)
{
    uint8_t cnt = 8;
    uint8_t result = 0;
    DS1302CS = 1;

    DS1302Sck = 1;
    while (cnt--)
    {
        _nop_();
        DS1302Sck = 0;
        _nop_();
        result += DS1302Dat;

        DS1302Sck = 1;

        result <<= 1;
    }

    DS1302CS = 0;
    return result;
}

int main()
{

    while (1)
    {
    }
}
