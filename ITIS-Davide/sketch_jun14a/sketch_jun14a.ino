#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;


void setup() {
  myservo2.attach(A5,180,360);
  myservo1.attach(A4,180,360);
}

void loop() {
  /*for(int i=0;i<1000;i=i+100){
  myservo.write(i);                  // sets the servo position according to the scaled value
  delay(15);
  }  */                        
 /* for(int i=1000;i<2000;i=i+100){
  myservo.write(i);                  // sets the servo position according to the scaled value
  delay(15);
  }*/

while(1){
  myservo2.write(360);
  myservo1.write(180); 
}
}
