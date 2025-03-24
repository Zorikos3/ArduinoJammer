# ArduinoJammer 🚠
DIY Arduino Uno 3 Bluetooth Jammer!

------------------------

Diagram to Connect Modules to UNO 3:

nRF24L01+  →  Arduino

GND        →  GND
VCC        →  3.3V  ⚠️ (Do NOT use 5V, your module will get fucking fried)
CE         →  D9
CSN        →  D10
SCK        →  D13
MOSI       →  D11
MISO       →  D12
IRQ        →  (Not used)

------------------------

Uploading Code:

1) Download Arduino IDE (https://www.arduino.cc/en/software/)
2) Go to libraries and Install "RF24" & "Arduino Uno".
3) Select COM port and "Arduino Uno".
4) Paste the code from "code.cpp"!
5) Click verify and the upload so the "Check" then the "Arrow"!
6) Then You will have a working Bluetooth Jammer!

------------------------
By the way the jammer:

- Jams all 125 Channels
- Is powerful
- Works

------------------------

WARNINGS:

ALWAYS HAVE THE ANTENNA CONECTED TO THE MODULE!!!!

FIRST CONNECT THE WIRES TO THE NRF24 WITH THE ANTENNA AND THEN FLASH THE FIRMWARE!!!!!

ON VCC USE 3V3 NOT 5V OR YOU WILL BE FUCKING COOKED!!!!!!

------------------------
Made by Zorikos3 on Discord, peace!
