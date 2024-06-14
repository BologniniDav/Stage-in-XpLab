#include <PWMServo.h>

PWMServo myservo;  // create servo object to control a servo


int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(A5,0,180);         // attaches the servo on pin 9 to the servo object
  //myservo.attach(SERVO_PIN_A, 1000, 2000); // some motors need min/max setting
}

void loop() {
  for(int i=90;i<180;i++){
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);
  }                           
  for(int i=90;i>0;i--){
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);
  }
}
