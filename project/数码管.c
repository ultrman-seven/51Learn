#include "common.h"
#include "reg51.h"

#define __SMG_TEST_

sbit smg138D0 = def_s_bit(P2, 2);
sbit smg138D1 = def_s_bit(P2, 3);
sbit smg138D2 = def_s_bit(P2, 4);

/**
 * @brief
 *
 * @param uint8_t posi
 * @return void
 */
void hc138Set(uint8_t posi)
{
    if (posi <= 7)
    {
        smg138D0 = posi & 0x01;
        smg138D1 = posi & 0x02;
        smg138D2 = posi & 0x04;
    }
}

enum smgCH
{
    // smgZero,smgOne,smgTwo,smgThree,smgFour,smgFive,smgSix,smgSeven,smgEight,smgNine,

    smgNull = 10,
    smg_,
    smgDot
};

code uint8_t smgImg[] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66,
    0x6d, 0x7d, 0x03, 0x7f, 0x6f,
    0x00, 0x40, 0x80};

#define smgCharPort P0

/**
 * @brief
 * @param {int32_t} num
 * @return {*}
 */
void smgShowIntNumInLoop(int32_t num)
{
    int8_t numSign = num >= 0 ? 1 : -1;
    uint8_t portMask, displayBit = 0;
    if (num > 99999999)
        num = 99999999;
    if (num < -9999999)
        num = -9999999;
    num *= numSign;

    while (num)
    {
        smgCharPort = smgImg[smgNull];
        portMask = smgImg[num % 10];
        num /= 10;
        hc138Set(displayBit++);
        smgCharPort = portMask;
        delay(20);
    }
    if (numSign < 0)
    {
        smgCharPort = smgImg[smgNull];
        portMask = smgImg[smg_];
        hc138Set(displayBit);
        smgCharPort = portMask;
        delay(20);
    }
}

void smgShowIntNumInLoop(int32_t num)
{
}

#ifdef __SMG_TEST_
int main()
{
    while (1)
    {
        smgShowIntNumInLoop(-114514);
    }
}
#endif
