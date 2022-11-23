#include <functions.h>


// Setup function
void start(int IN1,int IN2,int IN3,int IN4){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

}



// Control function
void handler(char command,int IN1,int IN2,int IN3,int IN4){
  switch (command){

    case 'F':
      front_or_back(true, IN1, IN2, IN3, IN4);
      break;

    case 'B':
      front_or_back(false, IN1, IN2, IN3, IN4);
      break;


    case 'R':
      right_or_left(true, IN1, IN2, IN3, IN4);
      break;

    case 'L':
      right_or_left(false, IN1, IN2, IN3, IN4);
      break;

    default:
      stop(IN1, IN2, IN3, IN4);
      break;

  }

}



// Move functions
void front_or_back(bool is_front,int IN1,int IN2,int IN3,int IN4) {
    
  digitalWrite(IN1, is_front);
  digitalWrite(IN2, not is_front);

  digitalWrite(IN3, is_front);
  digitalWrite(IN4, not is_front);
}

void right_or_left(bool is_right,int IN1,int IN2,int IN3,int IN4) {
    
  digitalWrite(IN1, is_right);
  digitalWrite(IN2, not is_right);

  digitalWrite(IN3, not is_right);
  digitalWrite(IN4, is_right);
}

void stop(int IN1,int IN2,int IN3,int IN4) {
    
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}



// Test functions
void test_motor(HardwareSerial *SerialN,int time_delay,int IN1,int IN2,int IN3,int IN4){
  
  SerialN->println("roda direita sentido horario");
  test_right(true, IN1, IN2, IN3, IN4);
  delay(time_delay);

  SerialN->println("roda direita sentido anti-horario");
  test_right(false, IN1, IN2, IN3, IN4);
  delay(time_delay);

  SerialN->println("roda esquerda sentido horario");
  test_left(true, IN1, IN2, IN3, IN4);
  delay(time_delay);

  SerialN->println("roda esquerda sentido anti-horario");
  test_left(false, IN1, IN2, IN3, IN4);
  delay(time_delay);
}

void test_right(bool is_clockwise,int IN1,int IN2,int IN3,int IN4){
  digitalWrite(IN1, is_clockwise);
  digitalWrite(IN2, not is_clockwise);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void test_left(bool is_clockwise,int IN1,int IN2,int IN3,int IN4){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, is_clockwise);
  digitalWrite(IN4, not is_clockwise);
}