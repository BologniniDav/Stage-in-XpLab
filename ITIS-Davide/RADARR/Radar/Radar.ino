#include <Servo.h>
unsigned short crv[6];
#define HEADSAM 0xFAFB

#define CRV_HEAD crv[0]
byte* buff;

long* dist;

#define trigPin 6
#define echoPin 7
#define trigPin2 5
#define echoPin2 4

long durata, cm;
long durata2, cm2;

  Servo servo;
  
void setup() {


  servo.attach(10);  
  servo.write(0);  

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  CRV_HEAD= HEADSAM;
  buff= (byte*) crv;
  
 
}
void loop()
{
  for (int angle = 0; angle <= 180; angle=angle+10) { 
    servo.write(angle);
    delay(25); 
    radar();
    crv[5] = angle;
    Serial.write(buff, 12);
 // Serial.print("Cm = ");
 // Serial.println(cm);
 // Serial.println();  
  //Serial.print("Cm2 = ");
  //Serial.println(cm2);
  //Serial.println();       
  }



  
  for (int angle = 180; angle >= 0; angle=angle-10) {  
    servo.write(angle);
    delay(25); 
    radar(); 
    crv[5] = angle;
    Serial.write(buff, 12);                         
    //Serial.print("Cm = ");
    //Serial.println(cm);
    //Serial.println();  
    //Serial.print("Cm2 = ");
    //Serial.println(cm2);
    //Serial.println(); 
}
}
void radar(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durata = pulseIn(echoPin, HIGH);
  cm=durata / 58; 
  *(long*)&crv[1] = cm; 
  delay(20);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  durata2 = pulseIn(echoPin2, HIGH);
  cm2=durata2 / 58;
  *(long*)&crv[3] = cm2;
  delay(20);
  
}
