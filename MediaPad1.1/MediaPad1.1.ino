#include <ClickEncoder.h>
#include <TimerOne.h>
#include <HID-Project.h>


//define encoder1 pins
#define ENCODER1_CLK A0 //Analog pin A0 for rotary encoder1
#define ENCODER1_DT A1 //Analog pin A1 for rotary encoder1
#define ENCODER1_SW 15 //digital pin for encoder1 button

//define encoder2 pins
#define ENCODER2_CLK A2 //Analog pin A0 for rotary encoder2
#define ENCODER2_DT A3 //Analog pin A1 for rotary encoder2
#define ENCODER2_SW 14 //digital pin for encoder2 button


//define button pins 
#define PINA 8 //Digital pin 8 for keyA
#define PINB 9 //Digital pin 9 for keyB

ClickEncoder *encoder1; // variable representing the rotary encoder1
ClickEncoder *encoder2; // variable representing the rotary encoder2

int16_t last1, value1; // variables for current and last rotation value on encoder1
int16_t last2, value2; // variables for current and last rotation value on encoder2

void timerIsr() {
  encoder1->service();
  encoder2->service();
}

void setup() {


//key setup
  pinMode(PINA, INPUT_PULLUP); 
  pinMode(PINB, INPUT_PULLUP);

//knob setup
  Serial.begin(9600); // Opens the serial connection used for communication with the PC. 
  Consumer.begin(); // Initializes the media keyboard
  encoder1 = new ClickEncoder(ENCODER1_DT, ENCODER1_CLK, ENCODER1_SW); // Initializes the rotary encoder1 with the mentioned pins
  encoder2 = new ClickEncoder(ENCODER2_DT, ENCODER2_CLK, ENCODER2_SW); // Initializes the rotary encoder2 with the mentioned pins

  Timer1.initialize(1000); // Initializes the timer, which the rotary encoder uses to detect rotation
  Timer1.attachInterrupt(timerIsr); 
  last1 = -1;
  last2 = -1;

} 

void loop() {  
  value1 += encoder1->getValue();
  value2 += encoder2->getValue();
  
  //This part is responsible for the buttons

  if (digitalRead(PINA) == LOW) //check if button B is pressed
  {
    Consumer.write(CONSUMER_CALCULATOR);  //Temporarily opens calculator app
    delay(200);
  }

  if (digitalRead(PINB) == LOW) //check if button C is pressed
  {
      //Using app LightBulb, this key combination reduces brightness and dimms the screen
        delay(200); // This delay prevents double click
        Keyboard.press(KEY_LEFT_CTRL); //press left ctrl
        Keyboard.press(KEY_LEFT_ALT); //press left alt
        Keyboard.press(KEY_L); //press L
        delay(100);
        Keyboard.releaseAll(); //release all buttons
      
  }


  // This part of the code is responsible for the actions when you rotate the encoder1
  if (value1 != last1) { // New value is different than the last one, that means to encoder1 was rotated
    if(last1<value1) // Detecting the direction of rotation
    {
      Consumer.write(MEDIA_VOLUME_UP); // Rotating counter-clockwise
      delay(60);
    }
      else
    {
      Consumer.write(MEDIA_VOLUME_DOWN); // Rotating clockwise
      delay(60);
    }
    last1 = value1; // Refreshing the "last" varible for the next loop with the current value


    //Serial.print("Encoder1 Value: "); // Text output of the rotation value used manily for debugging (open Tools - Serial Monitor to see it)
    // Serial.println(value1);
  }

  // This part of the code is responsible for the actions when you rotate the encoder2
  if (value2 != last2) { // New value is different than the last one, that means to encoder2 was rotated
    if(last2<value2) // Detecting the direction of rotation
    {
      Consumer.write(MEDIA_NEXT); // Rotating counter-clockwise
      delay(160);
    }
      else
    {
      Consumer.write(MEDIA_PREVIOUS); // Rotating clockwise
      delay(160);
    }

    last2 = value2; // Refreshing the "last" varible for the next loop with the current value


    //Serial.print("Encoder2 Value: "); // Text output of the rotation value used manily for debugging (open Tools - Serial Monitor to see it)
    //Serial.println(value2);
  }

  // This next part handles the rotary encoder1 button
  ClickEncoder::Button a = encoder1->getButton(); // Asking the button for it's current state
  if (a != ClickEncoder::Open) { // If the button is unpressed, we'll skip to the end of this if block
    switch (a) {
      case ClickEncoder::Clicked: // Encoder1 was clicked once
        {
        //Switch sound source with SoundSwitch program.

        Keyboard.press(KEY_LEFT_CTRL); //press left ctrl
        Keyboard.press(KEY_LEFT_ALT); //press left alt
        Keyboard.press(KEY_F11); //press f11
        delay(100);
        Keyboard.releaseAll(); //release all buttons
      
        
        } 
      break;      
      
      case ClickEncoder::DoubleClicked: // Encoder1 was double clicked
        Consumer.write(MEDIA_VOLUME_MUTE); //Mute sound 
      break;   
    }
  }

     // This next part handles the rotary encoder2 button
  ClickEncoder::Button b = encoder2->getButton(); // Asking the button for it's current state
  if (b != ClickEncoder::Open) { // If the button is unpressed, we'll skip to the end of this if block
    switch (b) {
      case ClickEncoder::Clicked: // Encoder2 was clicked once
        {
        //Play / Pause
       Consumer.write(MEDIA_PLAY_PAUSE);
       delay(200);
      
        } 
      break;   
      	
      case ClickEncoder::DoubleClicked: // Encoder2 was double clicked
        Consumer.write(CONSUMER_BROWSER_HOME); // Temporarily opens Homepage of default browser 
      break;     
      
  }
}}

        
