Class survey project
by: Joakim Englund, Daniel Örhill, Mohib Ali Akbari

# Table of Content
- Discription
- Requirements
- Hardware
- Program
- File structure

## Discription
Basic survey tool built with an ATmega328P MCU, three buttons (green, yellow, and red), a screen and a secondary chip for wifi.\
The screen displays a question that can be answerred by pressing any of the buttons.\
The data then gets uploaded to thingspeak where it can be analysed.

Based on [native-blink](https://github.com/aspcodenet/native-blink/) and [avrwifi (testing branch)](https://github.com/aspcodenet/avrwifi/tree/testing).

The project is simulated on [Wokwi](https://wokwi.com/projects/378185869128599553).

 ### Example:
LCD: How was class today?
```
Button1 = Good   Button2 = Okay   Button3 = Bad
```
The students would either press one of the three buttons.

## Requirements
The requirements given to us when we got the assignment.
### Code
- C code prefered but Cpp is fine
- No GPL-licensed code

### Hardware
- OLED/LCD Screen
- 3 buttons (Green, Yellow, Red)
- ESP8266 with Wifi

## File Structure



