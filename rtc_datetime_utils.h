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

#ifndef __RTC_DATETIME_UTILS__
#define __RTC_DATETIME_UTILS__
#include <stdint.h>
#include <rtc3231.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Increment second in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void increment_second(rtc_datetime_t *dt);

/**
 * Decrement second in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void decrement_second(rtc_datetime_t *dt);

/**
 * Increment minute in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void increment_minute(rtc_datetime_t *dt);

/**
 * Decrement minute in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void decrement_minute(rtc_datetime_t *dt);

/**
 * Increment hour in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void increment_hour(rtc_datetime_t *dt);

/**
 * Decrement hour in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void decrement_hour(rtc_datetime_t *dt);

/**
 * Increment day in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void increment_day(rtc_datetime_t *dt);

/**
 * Decrement day in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void decrement_day(rtc_datetime_t *dt);

/**
 * Increment month in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void increment_month(rtc_datetime_t *dt);

/**
 * Decrement month in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void decrement_month(rtc_datetime_t *dt);

/**
 * Increment year in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void increment_year(rtc_datetime_t *dt);

/**
 * Decrement year in datetime data structure.
 * @param dt: *rtc_datetime_t
 */
void decrement_year(rtc_datetime_t *dt);

#ifdef __cplusplus
}
#endif
#endif