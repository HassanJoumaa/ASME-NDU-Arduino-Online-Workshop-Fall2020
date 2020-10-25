/*
Push-Button Circuit Imitation:
1) Use the input value from a push-button to keep the Led ON while the button is pressed down and OFF otherwise.
2) When the button is ON print "one statement each time" saying so. 
Hint: Use a Flag variable.
*/

const int Led=11; //Initialize Led1 at pin number 11. 
const int button=7; //Initialize button at pin number 7.
void setup()
{
  pinMode(button, INPUT); //Set button to INPUT
  pinMode(Led, OUTPUT); //Set Led to OUTPUT
  digitalWrite(Led, LOW); //Set Led to LOW.
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600 
  
}

void loop()
{
  int flag=1;
  //While the button is pressed down.
  while(digitalRead(button)){ 
    digitalWrite(Led, HIGH); //Turn ON the Led.
    if(flag){
      Serial.println("Led is ON!");
      flag=0; //Set flag to "0" so that the if statement doesn't get triggered again.
    }
  }
  digitalWrite(Led, LOW); //Turn Led OFF
  delay(50); //If the program has no delays it's good to add a small one.
}
