# Arduino_LED

Sound Reactive LEDs with Python Communication

Arduino Hardware:
In this project, the LED strip is connected to the breadboard with the green wire from the LED strip connected to pin 2 of the Arduino. The positive and negative wires of the LED strip are connected to the respective positive and negative lines on the breadboard. 
The sound sensor, on the other hand, is connected to the breadboard with the orange wire from the sound sensor connected to the A0 pin on the Arduino, and the black and green wires of the sound sensor connected to the respective positive and negative lines on the breadboard. 
Additionally, there is a red wire from the Arduino 5V port connected to the positive line on the breadboard and a black wire from the Arduino GND port connected to the negative line on the breadboard. 
It can be set up through the Arduino USB port or by a 5V power supply.
This setup allows for the sound sensor to detect sound levels and adjust the brightness of the LED strip accordingly, creating a sound-reactive effect.

Arduino IDE:
The code in the IDE is a program for an Arduino that controls a LED strip based on sound input. The LED strip is reactive to sound, meaning that the brightness and color of the LEDs will change based on the sound level detected by a sound sensor.
The program uses a library: FastLED, which helps with the manipulation of the LED strip. https://fastled.io/docs/3.1/index.html
The program defines several constants, including the number of LEDs on the strip, the pin the LED data is connected to, the pin the sound sensor is connected to, and the minimum and maximum sound levels that will trigger the LEDs. Additionally, the program defines constants related to LED brightness and color, such as the LED color and the amount the gradient changes between LEDs.
In the setup function, the program sets the serial communication baud rate to 9600. It specifies the rate that the bits are transmitted over the serial line. Then using the ‘FastLED.addLeds()’ function, it initializes the LED strip and sets up the strip and pin the Arduino is connected to. 
In the loop function, the program reads the sound level from the sound sensor, converts it to decibels using a formula, and stores it. The if statements check if the sound level is within range and adjusts it if its not. It then calls the soundReactive function, which sets the brightness and color of the LEDs based on the sound level. Finally, it keeps looping until the program stops. 
The soundReactive function uses a loop to set the current color of each LED to an HSV color determined by the current value of the hue and the brightness value calculated earlier. HSV stands for hue, saturation, and value where colors are defined by their hue. The hue value is incremented by a set amount between LEDs, creating a gradient effect. 
Finally, the program updates the LED strip to reflect the changes in brightness and color made by the soundReactive function.

Python IDLE:
This code reads data from the Arduino serial port and saves it to a CSV file, while also displaying a real-time graph of the data. It imports the required libraries for working with serial data, data manipulation, and graph plotting.
Then initializes the serial port at a specified baud rate and sets up a list to store the incoming data. It also creates an empty pandas DataFrame to store the data for later manipulation.
Next, it opens a file in append mode to write the data to. The interactive mode for Matplotlib is turned on, and the code enters a loop that runs as long as the serial port is open.
Inside the loop, it reads a line of data from the serial port and decodes it as UTF-8. The data is then printed to the console, appended to the list, and written to the CSV file. The data is also added as a new column to the DataFrame.
It clears the current figure, plots the data, adds a title to the graph, and draws the updated plot. It saves the plot as an image and then repeats the loop.
Overall, it continuously reads data from a serial port, saves it to a file, and plots it in real-time using Matplotlib.
