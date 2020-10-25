/*
Controlling the Led using Serial Communication.
This project is done using 2 methods:
1) Using if statements. Let "1" be for ON and "0" be for OFF.
2) Without if statements.
Hint: Write each method in its own function.
*/

const int Led=11; //Initialize Led1 at pin number 11. 
int value; //Used to store the Serial input
void setup()
{
  pinMode(Led, OUTPUT); //Set Led to OUTPUT
  digitalWrite(Led, LOW); //Set Led to LOW.
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600 
  value = 0; //Set it initially to "0"
}

void loop()
{
  if(Serial.available()){ //if something was sent over the serial port
   value = Serial.parseInt(); //Set value equal to that int. 
   Serial.println(value);
  }
  
  //Choose the method you want to use and comment the other. 
  method1();
  //method2();
}

//method1 uses if statements
void method1(){
  if(value==1){digitalWrite(Led, HIGH);}
  else if(value==0){digitalWrite(Led, LOW);}
}

//method2 doesn't use if statements
void method2(){
  digitalWrite(Led, value);
}
