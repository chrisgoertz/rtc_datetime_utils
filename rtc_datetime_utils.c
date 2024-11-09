/*                   GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

* This is my helper library for dealing with time, date and
* calendar datastructure of my DS3231 library.
* It will be used in context of microcontroller applications.
* 
* copyright (C) Christian Goertz <chris.goertz@gmx.de>
*/
#include "rtc_datetime_utils.h"

#include <stdint.h>
#include <stdbool.h>

#include <rtc3231.h>

#define SECOND_MAX      (59)
#define MINUTE_MAX      (59)
#define HOUR_MAX        (23)

// Enumeration for easier fiddling around
// with month names.
enum m_length {
    INVALID,
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
    m_length_max
};

/* Month length in days */
static const uint8_t month_lengths[m_length_max] = {
    0, // invalid
    31, // Jan
    28, // Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31  // Dec
    };

bool _is_leapyear(uint16_t year)
{
    return ( (year % 4 == 0) && (year % 100 != 0) || (year %400 == 0));
}

void increment_second(rtc_datetime_t *dt)
{
    if(++(dt->sec) < SECOND_MAX)
    {
        return;
    }
    dt->sec = 0;
    increment_minute(dt);
}

void decrement_second(rtc_datetime_t *dt)
{
    if(!(dt->sec))
    {
        --(dt->sec);
    }
    else
    {
        dt->sec = SECOND_MAX;
        decrement_minute(dt); 
    }
}

void increment_minute(rtc_datetime_t *dt)
{
    if(++(dt->min) < MINUTE_MAX)
    {
        return;
    }
    dt->min = 0;
    increment_hour(dt);
}

void decrement_minute(rtc_datetime_t *dt)
{
    if(!(dt->min))
    // if minute is not zero,
    // decrement minute
    {
        --(dt->min);
    }

    else
    // otherwise minute will overflow,
    // so set minute to max value and
    // decrement hour.
    {

        dt->min = MINUTE_MAX;
        decrement_hour(dt);
    }
}

void increment_hour(rtc_datetime_t *dt)
{
    if(++(dt->hour) < HOUR_MAX)
    // pre increment hour and test if
    // hour exceeds limit
    {
        // fine
        return;
    }

    // otherwise hour overflows so, 
    // reset hours and increment day
    dt->hour = 0;
    increment_day(dt);
}

void decrement_hour(rtc_datetime_t *dt)
{
    if(dt->hour > 0)
    {
        --(dt->hour);
    }
    else
    {
        dt->hour = HOUR_MAX;
        decrement_day(&dt);
    }
}

void increment_day(rtc_datetime_t *dt)
{
    // if the actual year is a leapyear,
    // set the offset to 1.
    uint8_t leapyear_offset = _is_leapyear(dt->year)+ 2000 ? 1 : 0;
    
    // calculate the length of this month
    uint8_t length_of_this_month = dt->month == FEB ? month_lengths[dt->month] + leapyear_offset : month_lengths[dt->month];
    
    // increment day and test if length of this month
    // is exceeded.
    if(++(dt->day) < length_of_this_month)
    {
        // not exceeded, done!
        return;
    }
    else
    {
        // exceeded, so reset day and increment month.
        dt->day = 0;
        increment_month(&dt);
    }

}
void decrement_day(rtc_datetime_t *dt);
void increment_month(rtc_datetime_t *dt);
void decrement_month(rtc_datetime_t *dt);
void increment_year(rtc_datetime_t *dt);
void decrement_year(rtc_datetime_t *dt);
