# RGB Color Picker with Arduino

This project uses an Arduino, an RGB LED, a potentiometer, and a 0.93" OLED display to create a simple color picker.

By rotating the potentiometer, the RGB LED smoothly changes its color. At the same time, the OLED display shows the current color as a HEX code, making it easy to recreate the selected color in software or other projects.

## Features

* Real-time RGB color changes
* Color selection using a potentiometer
* Live HEX color code display
* 0.93" OLED screen output
* Great beginner Arduino project for learning analog inputs and displays

## Hardware Used

* Arduino Uno/Nano
* RGB LED
* Potentiometer
* 0.93" OLED display
* Resistors and jumper wires

Component	Arduino Pin
🎚️ Potentiometer	A0
🔴 RGB LED – Red	D9
🟢 RGB LED – Green	D10
🔵 RGB LED – Blue	D11
OLED SDA	A4
OLED SCL	A5
OLED VCC	5V
OLED GND	GND
Potentiometer
One outer pin → 5V
Middle pin → A0
Other outer pin → GND
RGB LED

For a common-cathode RGB LED:

Red → 220–330 Ω resistor → D9
Green → 220–330 Ω resistor → D10
Blue → 220–330 Ω resistor → D11
Common cathode → GND

The OLED uses I²C, so on the UNO:

SDA = A4
SCL = A5
