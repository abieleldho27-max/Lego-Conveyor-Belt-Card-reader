# Lego-Conveyor-Belt-Card-reader
## Overview
This is a custom conveyor-belt card reader that can read custom LEGO keys to execute commands. I use LEGO for the conveyor belt and keys, and I use an Arduino UNO R3 to power it. The conveyor belt is powered by a stepper motor, and the code is read by a photoresistor.
## Features
- Reads custom keys
- You can program the reading to do something, like turn on an LED
- You can create your own keys and put them into the code so that they are recognizable.
- You can store multiple keys with different commands, or set a few keys to one command
## Components Used
- Lego bricks and components
- 1 28BYJ-48 Stepper Motor
- 1 ULN2003 Stepper Driver
- 1 Photoresistor (Photocell)
- 3 LEDs
- 2 220Ω resistors
- 1 1kΩ resistor
- 1 Breadboard
- Jumper wires
- 1 pushbutton
- 1 Arduino UNO R3 (Elegoo)
- 1 External Power Supply Module
## Wiring
Photoresistor - A0
Signal LED pin - D2
Code 1 LED - D7
Code 2 LED - D12
Pushbutton - D4
IN1 - D8
IN2 - D9
IN3 - D10
IN4 - D11
## How it works
A lamp shines light onto a photoresistor. The stepper motor connected to the conveyor belt moves the key across the photoresistor when the button is pressed. Teeth on the key block light in a specific pattern, which is read by the photoresistor and stored as a string of 1's and 0's (1 if light is being blocked, 0 if light is hitting the resistor). Every time it reads the light, it checks if the code being stored matches any of the saved codes. If it matches, it executes the assigned command. If not, it continues to read the code. Because the controller can only execute one step at a time, it moves the belt in increments by running a function that I created multiple times. The function tells the motor to step 4 times, so the more you run this function, the more the belt moves. Then, after the function has run as many times as written, it scans for light. It continues this process until it recognizes a code, as I mentioned earlier. I wrote the function 6 times because the belt moves approximately half of a stud when the button is pressed in each increment, which makes the reading much more consistent. Also, the code reading resets every time you press the button, and when the code exceeds a certain number of characters. This means you must hold the button down when reading the key, and you can restart the reading if it messes up in the middle of a reading.
## Challenges
One of the biggest challenges I faced was getting a consistent reading. I initially did not plan on using a conveyor belt to move the key, since I was initially going to move it by hand. But the readings I was getting were inconsistent, and moving the brick across the small resistor was tedious. So to solve this, I incorporated the conveyor belt. This makes it much easier and more reliable when reading the code because the key moves at a consistent speed and does not move around as much. This way, the resistor was able to pick up on the patterns much better and the code was being executed properly. Another factor that was affecting the consistency of the readings was the key. When the belt moved in increments, It would often stop at the edge of a tooth, which would make it harder to predict whether it would read a 1 or a 0. To fix this, I calibrated the belt so that each increment was about half a stud. This way, I was able to get the key to stop directly under the teeth or directly in a space, which made it easier for the resistor to register the intended value.
## Future Improvements
- Create a system that can read keys of different lengths
- Improve the reading system to make it more consistent, while also allowing it to read more complex codes
- make it more compact, and possibly create a body that houses all the electronics
## What I learned
- How to use a photoresistor and how to read the voltage changes using an analog pin
- How to use a stepper motor without a library
- How to add characters to strings and how to check for strings within strings using ```substring()```
## Author
Abiel Eldho
