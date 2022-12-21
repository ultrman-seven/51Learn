#ifndef __Wy_51LIB_DS1302_H__
#define __Wy_51LIB_DS1302_H__
#include "common.h"

// #define HourClock24
#define HourClock12
typedef struct
{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
#ifdef HourClock12
    uint8_t isMorning;
#endif
    uint8_t min;
    uint8_t sec;
    uint8_t week;
} TimeUnit;
typedef enum
{
    DS1302_TimeTypeSecond = 0x00, // = DS1302_REG_Sec,
    DS1302_TimeTypeMin,
    DS1302_TimeTypeHour,
    DS1302_TimeTypedDay,
    DS1302_TimeTypeMonth,
    DS1302_TimeTypeWeek,
    DS1302_TimeTypeYear,
} DS1302_TimeTypes;

void DS1302_SetSingleTime(DS1302_TimeTypes timeType, uint8_t t);
uint8_t DS1302_GetSingleTime(DS1302_TimeTypes timeType);
void DS1302_SetTime(TimeUnit *t);
void DS1302_GetTime(TimeUnit *t);
void DS1302_Run();
void DS1302_Stop();
#endif /* __Wy_51LIB_DS1302_H__ */
