/*
The project consists of using an H-bridge to control a 
DC motor and its direction controlled by switches connected 
directly to the Arduino. You should have three push buttons 
connected to the Arduino and the Arduino output will be 
connected to the H-bridge.

The DC Motor direction of rotation is controlled via 
the push-button labeled btnSwitch: after TWO presses of 
btnSwitch, the motor will switch direction.

The speed control of the motor is implemented with 5 different 
discrete speeds controlled by 2 push-button switches. 
One push-button switch (labeled btnUP) will be used in order
to increase the motor speed and the other push-button 
(labeled btnDown) for decreasing motor speed. 

The five speed states of the motor are given on a scale with respect to its
maximum speed (0%, 25%, 50%, 75%, 100% of its maximum speed). 
After each pushbutton control, the speed of the motor will 
increase by one state(when btnUP is pressed)or decrease 
by one state(when btnDown is pressed).

Note: Pay attention not to connect directly the motor to the 
Arduino output. The motor should be connected via an L293D H-bridge.


A RGB LED is a Light Emitting Diode that can output different 
colors based on its inputs. In order to visualize more the 
motor speed state, one RGB LED will be connected to the 
appropriate outputs of the Arduino and will output a color
based on the DC motor speed state, as follows:
• LED light will be BLUE when the DC motor speed is at 0%
• LED light will be GREEN when the DC motor speed is at 25%
• LED light will be YELLOW when the DC motor speed is at 50%
• LED light will be ORANGE when the DC motor speed is at 75%
• LED light will be RED when the DC motor speed is at 100%

*/


//Setting up motor to "pwm" digital pins 10 and 11.
const int m1a=11;
const int m1b=10;
//Motor states, false means it's connected to GND.
bool m1a_state= true; 
bool m1b_state=false;

//Setting up button pins
const int btnUP=2; //btnUp is used to increase the speed.
const int btnDown=4;//btnDown is used to decrease the speed.
const int btnSwitch=12;//btnSwitch is used to switch the rotation direction.
int rate = 0; //The speed rate
int switchCount=0; //Used as a counter to btnSwitch.

//Setting up RGB LED pins
const int red=3;
const int green=6;
const int blue=5;

void setup()
{
  //Initialize the pins
  initialize();
 
}


void loop()
{
  //If btnUp is pressed.
  if(digitalRead(btnUP)){
    if(check_rate(btnUP)){rate+=25;}//Increment rate by 25(rate=rate+25)
    wait(btnUP);
  }
  //If btnDown is pressed.
  else if(digitalRead(btnDown)){
    if(check_rate(btnDown)){rate-=25;}//Decrement rate by 25(rate=rate-25)
    wait(btnDown);
  }
  //If btnSwitch is pressed.
  else if(digitalRead(btnSwitch)){
    update_switch_count();
    if(switchCount==2){switch_rotation();}
    wait(btnSwitch);
  }
  //Update Motor and RGB Led values
  analogWrite(m1a, speed(m1a_state, rate));
  analogWrite(m1b, speed(m1b_state, rate)); 
  update_color(rate);
}

//This function is used to initialize the pins. 
void initialize(){
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(btnUP, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnSwitch, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
/*
This function is used with the buttons,
it waits until the button is released after it has been pressed.
*/
void wait(int btn){
  while(digitalRead(btn)){} //Do nothing and wait
}

/*
This function will check if we can increment/decrement
the rate depending on the button being pressed. 
It returns a bool of true or false.
*/
bool check_rate(int btn){
  //If btnUP is pressed.
  if(btn==btnUP){
    if(rate<100){return true;}
    else{return false;}
  }
  //If btnDown is pressed.
  else if(btn==btnDown){
    if(rate>0){return true;}
    else{return false;}
  }
  /*If anything else is pressed.
  (This happens only if this function was miss-used.
  For example if it was used with btnSwitch.)
  */
  else{return false;}
}
 
/*
This function will update the Switch button counter
every time btnSwitch gets pressed.
*/
void update_switch_count(){
  if(switchCount<2){switchCount++;}
  else{switchCount=1;}
}

/*
This function will switch the motor states, every time 
switchCount is equal to 2.
*/
void switch_rotation(){
  m1a_state= !m1a_state; //Switch the state of m1a.
  m1b_state= !m1b_state; //Switch the state of m1b.
}

/*
This function will calculate the pwm for the motor.
*/
int speed(bool state, int percentage){
  int spd;
  //If the state is true, calculate it's pwm.
  if(state){ spd = percentage*255*0.01;}
  //Else set a pwm of 0. Same as "LOW".
  else{spd=0;}
  return spd;
}

/*
This function is used to update the value of the 
RGB Led according to the motor's speed rate.
*/
void update_color(int percentage){
  //If rate is 0%, set RGB Led to Blue.
  if(percentage==0){rgb_color(0,0,255);} 
  //If rate is 25%, set RGB Led to Green.
  else if(percentage==25){rgb_color(0,255,0);}
  //If rate is 50%, set RGB Led to Yellow.
  else if(percentage==50){rgb_color(255,255,0);}
  //If rate is 75%, set RGB Led to Orange.
  else if(percentage==75){rgb_color(255,128,0);}
  //If rate is 100%, set RGB Led to Red.
  else{rgb_color(255,0,0);}
}

/*
This function is used to control the RGB Led,
it will help us minimize our code.
*/
void rgb_color(int red_color, int green_color, int blue_color){
	analogWrite(red, red_color);
    analogWrite(green, green_color);
  	analogWrite(blue, blue_color);
  }
