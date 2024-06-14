#include <Servo.h>

Servo servo6;

void setup() 
{
  Serial.begin(9600);

  servo6.attach(6);
}

void loop() 
{
  servo6.write(0);
}
