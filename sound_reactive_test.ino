//Shivane Rathore Sound Reactive LED Strip

//library
#include <FastLED.h>               //found a library that help with LEDs https://fastled.io

//pin constants
#define LEDS 150                //number of LEDs on strip
#define LED_PIN 2               //led is connected to data pin 2 (green wire)
#define SOUND_SENSOR_PIN A0     //connected to the sound sensor (red wire on breadboard)

//sound constants
#define SOUND_SENS_MAX 1000     //max level of sound that will be detected by the sound sensor [0-1023]
#define SOUND_SENS_MIN 150       //min level of sound that will trigger the LEDs [0-1023] (if sound is below LED will be off)
#define SOUND_MIN 0

//LED constants
#define LED_BRIGHTNESS 255        //changes the brightness of LEDs [0-255]
#define LED_SATURATION 150        //changes the saturation of LEDs [0-255] (0-greyscale and 255-fully saturated)
#define LED_COLOR 60              //LED HUE [0-255]       
#define LED_GRADIENT 5            //determines the amount the hue of each LED is changes from the previous one (creates gradient effect)  

//array
CRGB leds[LEDS];       //CRGB since LED is RGB for manipulation of each LED individually 

//variables
int i;
int soundLevel;
double dB;
byte brightnessValue; //byte for 8bit 
byte colorChange; //stores amount of change in hue applied to each LED

//funtion that sets up the LEDS
void setup() { 
  Serial.begin(9600); //serial monitor to see db data
  
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LEDS); //function to initizalize the LED - sets type of LED strip, pin in arduino, stores color values
}

//function
void loop() {
  //getting sound value (analog) and converting it to DB 
  soundLevel = analogRead(SOUND_SENSOR_PIN);
  dB = 20.0*log10(soundLevel+1.0);
  Serial.print("dB: ");  
  Serial.println(dB);
  
  //to make sure soundLevel stays in range of soundmax and soundmin
  if(soundLevel > SOUND_SENS_MAX) {
  soundLevel = SOUND_SENS_MAX;
  }
  if(soundLevel < SOUND_SENS_MIN) {
  soundLevel = 0;
  }

  soundReactive(); //calling function
  
  FastLED.show(); //updates the LED strip

  delay(100);
}

//function that creates sound reactiveness by setting brightness based on soundlevel and cycles through range of colors
void soundReactive() {
  //map(value(range), fromLow(min range of 'value'), fromHigh(max range of 'value'), toLow(min value to be mapped), toHigh(max value to be mapped));
  brightnessValue = map(soundLevel, SOUND_MIN, SOUND_SENS_MAX+1, SOUND_MIN, LED_BRIGHTNESS);

  //loop that sets the current color of the LED to an CHSV color that is determines by the current value of the hue and saturation
  for(i=0; i<=LEDS; i++) {
    //CHSV(hue, saturation, brightnessValue) - 
    leds[i] = CHSV(colorChange+=LED_GRADIENT, LED_SATURATION, brightnessValue); //hue is incremented by hue_change so each led will have aslightly different color    
  }
}



