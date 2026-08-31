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
 | Time             | HEX       | RGB           |
 | ---------------- | --------- | ------------- |
 | **Morning**      | `#FFAA00` | `255, 170, 0` |
 | **Late morning** | `#00AAFF` | `0, 170, 255` |
 | **Noon**         | `#FFFF00` | `255, 255, 0` |
 | **Afternoon**    | `#FF6600` | `255, 102, 0` |
 | **Evening**      | `#FF3300` | `255, 51, 0`  |
 | **Night**        | `#3300AA` | `51, 0, 170`  |
