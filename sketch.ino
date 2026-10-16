#include <Servo.h>
Servo doorServo;
int irEntry = 2;
int irExit = 4;
int prevState = HIGH;
bool objectPresent = false;
int count = 0;
const unsigned long gateTimeout = 5000;
unsigned long objectStartTime = 0;

void setup(){
  Serial.begin(9600);
  pinMode(irEntry, INPUT);
  pinMode(irExit, INPUT);
  doorServo.attach(3);
  doorServo.write(0);
  Serial.println("Conveyor Sorting System");
}

void loop(){
  int currState = digitalRead(irEntry);
  if((prevState == HIGH && currState == LOW) && !objectPresent){
    Serial.println("Object Arrived");
    objectStartTime = millis();
    objectPresent = true;
    count++;
    doorServo.write(90);
  }
  if(objectPresent && digitalRead(irExit) == LOW){
    doorServo.write(0);
    Serial.println("Object Dispatched");
    objectPresent = false;
    Serial.print("Total Count = ");
    Serial.println(count);
  }
  else if(objectPresent && (millis() - objectStartTime) >= gateTimeout){
    doorServo.write(0);
    objectPresent = false;
    Serial.println("WARNING: Exit Timeout!");
  }
  if(Serial.available() > 0){
    char command = Serial.read();
    if(command == 'R' || command == 'r'){
      count = 0;
      Serial.println("Product count reset to zero");
    }
  }
  prevState = currState;
}
