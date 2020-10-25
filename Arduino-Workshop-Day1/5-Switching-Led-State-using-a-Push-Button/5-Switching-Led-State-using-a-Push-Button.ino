/*
Switching LED state using a Push-Button:
1) Use the input value from a push-button to switch the Led state ON/OFF.
2) Print out the state of the Led.
Hint: Use a delay of 250 milliseconds as average time taken 
-to finish the push-button process. Adjust as needed. 
*/

const int Led=11; //Initialize Led1 at pin number 11. 
int state=0; //The current state of Led.
const int button=7; //Initialize button at pin number 7.
void setup()
{
  pinMode(button, INPUT); //Set button to INPUT
  pinMode(Led, OUTPUT); //Set Led to OUTPUT
  digitalWrite(Led, state); //Set Led to "0" which is equivalent to LOW.
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600 
  
}

void loop()
{
  int BtnValue = digitalRead(button);//Read the input value from button
  
  //If the button gets pushed
  if(BtnValue){ 
    state = !state; //Switch the state
    digitalWrite(Led,state); //Switch Led to ON or OFF depending on the state!
    if(state==1){Serial.println("Led is ON!");}
    else{Serial.println("Led is OFF!");}
    delay(250);//Average time taken to finish the push-button process. 
  }
   
}
