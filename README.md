# Arduino-RTC-RGB-segment-display-clock

## How does it work?

  When compiling the code, the compiler replaces the `__TIME__` and `__DATE__` macros with the computer's current time and date.

  The program then sends these values to the RTC (Real-Time Clock) module and sets its internal clock.

  This eliminates the need to manually set the RTC every time the code is uploaded.

  ## LED Colors

  The RGB LED changes its color depending on the current time of day:

  | Time of day      | LED color  |
  | ---------------- | ---------- |
  | **Morning**      | Orange     |
  | **Late morning** | Yellow     |
  | **Noon**         | White      |
  | **Afternoon**    | Light blue |
  | **Evening**      | Purple     |
  | **Night**        | Blue       |

The RTC provides the current time, which the program uses to determine the current time-of-day period and set the corresponding RGB LED color.

## To-Do list:

- [x] Create best-working clock with DS1302 RTC.
- [x] RTC works even through it's cutted of power. 
- [ ] Add displaying unique RGB color for each time of the day.
- [ ] Test if RGB is changing its color at each time of day.

## Components:

 - RTC (Real Time Clock) module
 - RGB (common anode) diode to show what time of the day is
 - LCD display to show what time is it 

## Colors of the time of the day:

| Time             | RGB            |
| ---------------- | -------------- |
| **Morning**      | `0, 85, 255`   |
| **Late morning** | `255, 85, 0`   |
| **Noon**         | `0, 0, 0`      |
| **Afternoon**    | `0, 153, 255`  |
| **Evening**      | `0, 204, 255`  |
| **Night**        | `204, 255, 85` |
