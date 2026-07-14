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
One of the biggest challenges I faced was getting a consistent reading. I initially did not plan on using a conveyor belt to move the key, since I was initially going to move it by hand. But the readings I was getting were inconsistent, and moving the brick across the small resistor was tedious. So to solve this, I incorporated the conveyor belt. This makes it much easier and more reliable when reading the code because the key moves at a consistent speed and does not move around as much. This way, the resistor was able to pick up on the patterns much better and the code was being executed properly. Another factor that was affecting the consistency of the readings was the key. When the belt moved in increments, It would often stop at the edge of a tooth, which would make it harder to predict whether it would read a 1 or a 0. To fix this, I calibrated the belt so that each increment was about half a stud. This way, I was able to get the key to stop directly under the teeth or directly in a space, which made it easier for the resistor to register the intended value. One more challenge thats currently affecting the consistency is placement. The placement of the key on the belt is so important because even the smallest shift in position will result in a different reading. It really only results in the resistor registering one or two digits differently, but it prevents the code from being executed. One remedy I found for this was adding multiple correct options with changes near the weak points that account for any discrepancies in the reading. But I decided not to do this anyway because it defeats the purpose of having a unique key, which is why I am still trying to find a solution.
## Future Improvements
- Create a system that can read keys of different lengths
- Improve the reading system to make it more consistent, while also allowing it to read more complex codes
- make it more compact, and possibly create a body that houses all the electronics
## What I learned
- How to use a photoresistor and how to read the voltage changes using an analog pin
- How to use a stepper motor without a library
- How to add characters to strings and how to check for strings within strings using ```substring()```
## Demo Vid
[YouTube Link](https://youtu.be/o5nOYBTWPyU)

## Photos
<img width="4284" height="5712" alt="IMG_9300" src="https://github.com/user-attachments/assets/49f48d06-10ce-419a-854e-1c895d78eee1" />
<img width="5712" height="4284" alt="IMG_9301" src="https://github.com/user-attachments/assets/d0114196-5d3c-40f1-925f-4e902af24f9f" />
<img width="4284" height="5712" alt="IMG_9302" src="https://github.com/user-attachments/assets/fd78aab4-7e48-4b7f-a6f8-bdb1b8cab850" />
<img width="3024" height="4032" alt="IMG_9303" src="https://github.com/user-attachments/assets/d30d47b2-2388-469e-b3bc-0fe3fd27ae86" />
<img width="5712" height="4284" alt="IMG_9285" src="https://github.com/user-attachments/assets/68561c3e-8bbd-4a96-98cb-435c24282192" />
<img width="5712" height="4284" alt="IMG_9287" src="https://github.com/user-attachments/assets/becf6557-dff5-498e-b7fb-b769850fda83" />
<img width="1206" height="2122" alt="IMG_9297" src="https://github.com/user-attachments/assets/49c01d6b-f30f-46a3-a298-5da3307f0683" />
<img width="4284" height="5712" alt="IMG_9298" src="https://github.com/user-attachments/assets/a550bf20-9149-4d41-a0e8-1131e039e226" />
<img width="3024" height="4032" alt="IMG_9299" src="https://github.com/user-attachments/assets/18db7db4-ec89-4448-8729-93816cb9a197" />


## Author
Abiel Eldho
