# Arduino-RTC-RGB-segment-display-clock
## Components:
 - RTC (Real Time Clock) module (I use Time library directly on Arduino board using board's processor clock and fetching time & date from PC while compiling code) 
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
