# Arduino-RTC-RGB-segment-display-clock

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
