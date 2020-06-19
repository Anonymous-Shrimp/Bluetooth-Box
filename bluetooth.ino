#include <SoftwareSerial.h>

bool newLineS = false;
const int relay = 2;
String input;
SoftwareSerial bluetooth(5, 4);
 
 
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
}

void loop()
{
  if(bluetooth.available()){
  while(bluetooth.available())
  {
    input += bluetooth.readString();
    delay(2);
  }
  Serial.println(input);
  
  
  if (input == "on"){
    
      bluetooth.println("Turning on...");
      digitalWrite(relay, LOW);
    
  }else if (input == "off"){
    
      bluetooth.println("Turning off...");
      digitalWrite(relay, HIGH);
    
  }else{
    bluetooth.println("Please enter on or off");
  }
  }

  input = "";
  

  }
  
