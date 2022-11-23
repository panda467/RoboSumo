#include <Arduino.h>
#include <functions.h>

int IN1 = 4,  IN2 = 6,  IN3 = 5,  IN4 = 7;

void setup() {
  Serial.begin(9600);
  start(IN1, IN2, IN3, IN4);

}

void loop(){
  if (Serial.available()){ 
    char command = Serial.read(); 
    handler(command, IN1, IN2, IN3, IN4);
  };
}