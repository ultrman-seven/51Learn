#include "ds1302.h"
#include "spi.h"

#define __DS1302_TEST 0
sbit DS1302CS = def_s_bit(P3, 5);

#define DS1302_REG_Sec (0x00)
#define DS1302_REG_Min (0x01)
#define DS1302_REG_Hour (0x02)
#define DS1302_REG_Day (0x03)
#define DS1302_REG_Month (0x04)
#define DS1302_REG_Week (0x05)
#define DS1302_REG_Year (0x06)

#define DS1302_REG_WriteProtect (0x07)
#define DS1302_WriteEnable (0x00)
#define DS1302_WriteDisable (0x80)

#define DS1302_REG_LowCharge (0x08)
#define DS1302_REG_ClockEmergency (0x09)

#define DS1302_RAM_Emergency (0x1f)

uint8_t __BCD2num(uint8_t n)
{
    uint8_t num;
    num = (n >> 4) & 0x0f;
    num *= 10;
    num |= (n & 0x0f);
    return num;
}
uint8_t __num2BCD(uint8_t n)
{
#if 0
    uint8_t bcd;

    bcd = n % 10;
    n /= 10;
    bcd |= (n << 4);

    return bcd;
#endif
    return n + 6 * (n / 10);
}

void __DS1302_SetReg(uint8_t reg, uint8_t dat)
{
    DS1302CS = 1;
    _nop_();
    reg <<= 1;
    reg |= 0x80;
    reg &= 0xfe;
    SPI_ReadByte(reg);
    SPI_SendByte(dat);
    DS1302CS = 0;
}

uint8_t __DS1302_ReadReg(uint8_t reg)
{
    uint8_t result;
    DS1302CS = 1;
    _nop_();
    reg <<= 1;
    reg |= 0x81;
    SPI_ReadByte(reg);
    result = SPI_ReadByte();
    DS1302CS = 0;
    return result;
}

/**
 * @brief en: .....
 * @param DS1302_TimeTypes timeType
 * @param uint8_t t
 */
void DS1302_SetSingleTime(DS1302_TimeTypes timeType, uint8_t t)
{
    t = __num2BCD(t);
    if (timeType == DS1302_TimeTypeSecond)
        t |= 0x80;
    if (timeType == DS1302_REG_Hour)
    {
#ifdef HourClock12
        t = 0x80 | __num2BCD(t);
#elif defined HourClock24
        t = 0x7f & (__num2BCD(t));
#endif
    }
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteEnable);
    __DS1302_SetReg(timeType, t);
}

/**
 * @description:
 * @param DS1302_TimeTypes timeType
 * @return uint8_t
 */
uint8_t DS1302_GetSingleTime(DS1302_TimeTypes timeType)
{
    uint8_t __r_time;
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteDisable);
    __r_time = __DS1302_ReadReg(timeType);
    if (timeType == DS1302_TimeTypeSecond)
        __r_time &= 0x7f;
    if (timeType == DS1302_TimeTypeHour)
    {
#ifdef HourClock12
        __r_time &= 0x1f;
#else
        __r_time &= 0x3f;
#endif
    }
    return __BCD2num(__r_time);
}

/**
 * @description:
 * @param {TimeUnit} *t
 * @return {*}
 */
void DS1302_SetTime(TimeUnit *t)
{
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteEnable);
    __DS1302_SetReg(DS1302_REG_Sec, 0x80 | __num2BCD(t->sec));
    __DS1302_SetReg(DS1302_REG_Min, __num2BCD(t->min));
    __DS1302_SetReg(DS1302_REG_Day, __num2BCD(t->day));
    __DS1302_SetReg(DS1302_REG_Week, __num2BCD(t->week));
    __DS1302_SetReg(DS1302_REG_Month, __num2BCD(t->month));
    __DS1302_SetReg(DS1302_REG_Year, __num2BCD(t->year));
#ifdef HourClock12
    __DS1302_SetReg(DS1302_REG_Hour, 0x80 | (t->isMorning << 5) | __num2BCD(t->hour));
#elif defined HourClock24
    __DS1302_SetReg(DS1302_REG_Hour, 0x7f & (__num2BCD(t->hour)));
#endif
}
void DS1302_GetTime(TimeUnit *t)
{
    uint8_t dat;
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteDisable);
    dat = __DS1302_ReadReg(DS1302_REG_Sec) & 0x7f;
    t->sec = __BCD2num(dat);
    dat = __DS1302_ReadReg(DS1302_REG_Min);
    t->min = __BCD2num(dat);
    dat = __DS1302_ReadReg(DS1302_REG_Month);
    t->month = __BCD2num(dat);
    dat = __DS1302_ReadReg(DS1302_REG_Day);
    t->day = __BCD2num(dat);
    dat = __DS1302_ReadReg(DS1302_REG_Week);
    t->week = __BCD2num(dat);
    dat = __DS1302_ReadReg(DS1302_REG_Year);
    t->year = __BCD2num(dat);

    dat = __DS1302_ReadReg(DS1302_REG_Hour) & 0x3f;
#ifdef HourClock12
    t->isMorning = dat & 0x20;
    dat &= 0xdf;
#endif
    t->hour = __BCD2num(dat);
}
void DS1302_Run()
{
    uint8_t currentSec;
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteDisable);
    currentSec = __DS1302_ReadReg(DS1302_REG_Sec);
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteEnable);
    __DS1302_SetReg(DS1302_REG_Sec, 0x7f & currentSec);
}
void DS1302_Stop()
{
    uint8_t currentSec;
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteDisable);
    currentSec = __DS1302_ReadReg(DS1302_REG_Sec);
    __DS1302_SetReg(DS1302_REG_WriteProtect, DS1302_WriteEnable);
    __DS1302_SetReg(DS1302_REG_Sec, 0x80 | currentSec);
}

#if __DS1302_TEST
int main(void)
{

    while (1)
    {
        /* code */
    }
}
#endif
