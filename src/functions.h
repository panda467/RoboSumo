#include <Arduino.h>

// Setup function
void start(int IN1,int IN2,int IN3,int IN4);

// Control function
void handler(char command,int IN1,int IN2,int IN3,int IN4);

// Move functions
void front_or_back(bool is_front,int IN1,int IN2,int IN3,int IN4);
void right_or_left(bool is_right,int IN1,int IN2,int IN3,int IN4);
void stop(int IN1,int IN2,int IN3,int IN4);

// Test functions
void test_motor(HardwareSerial *SerialN, int time_delay,int IN1,int IN2,int IN3,int IN4);
void test_right(bool is_clockwise,int IN1,int IN2,int IN3,int IN4);
void test_left(bool is_clockwise,int IN1,int IN2,int IN3,int IN4);