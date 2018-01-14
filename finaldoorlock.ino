#include <Servo.h>

Servo myservo;  

String input = "";
String cmd = "";
String check = "";
String password = "abcd";
boolean isComplete = false; 

void setup(){
 
  Serial.begin(9600);  
  
  boolean stringOK = false;
  
  myservo.attach(9); 
  
  input.reserve(100); 
  cmd.reserve(100);
  check.reserve(100);
  
  
}

void loop(){
 
  if (isComplete) {
    
    delay(100);
   
    int pos = input.indexOf('=');
    
    if (pos > -1) {
     
        cmd = input.substring(0, pos);
      
        check = input.substring(pos+1, input.length()-1);  
       
      
    if(!password.compareTo(check) && (cmd == "OPEN")){
         
           openDoor(); 
           Serial.println(" OPEN");
           delay(100);
           }
    else if(!password.compareTo(check) && (cmd == "CLOSE")){
          
           closeDoor();
           Serial.println(" CLOSE");
           delay(100);
           }
    else if(password.compareTo(check)){
          
           Serial.println(" WRONG");
           delay(100);
           } 
        } 
      
       input = "";
       isComplete = false;
    }
   
}


void serialEvent() {
  while (Serial.available()) {
  
    char inChar = (char)Serial.read(); 
    Serial.println(inChar);
    input += inChar;
   
    if (inChar == '\n' || inChar == '\r') {
      isComplete = true;
    } 
  }
}

void openDoor(){
  myservo.write(0); 
  delay(100);   
}

void closeDoor(){
  myservo.write(65);
  delay(100); 
}

