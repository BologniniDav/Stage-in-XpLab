#include <Wire.h>
unsigned short crv[10];
#define HEADSAM 0xFAFB

#define CRV_HEAD crv[0]
byte* buff;
long* dist;
#define trigPin 6

#define echoPin 7

long durata, cm;

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  

  CRV_HEAD= HEADSAM;
  buff= (byte*) crv;
  
  dist= (long*) &(crv[1]);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  
  CRV_HEAD= HEADSAM;
  buff= (byte*) crv;
}
int mult = 1;
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); 
  AcX=Wire.read()<<8|Wire.read();  
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  Tmp=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  crv[0]=0xFAFB;
  crv[1]=GyX;
  crv[2]=GyY;
  crv[3]=GyZ;
  crv[4]=AcX;
  crv[5]=AcY;
  crv[6]=AcZ;
  crv[7]=Tmp;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  if(Serial.available() > 0){
    mult=Serial.read();
  }
  durata = pulseIn(echoPin, HIGH);
  cm=durata / 58;
  *(long*)& crv[8]= cm; 
  

  Serial.write(buff, 20);

 
  /*Serial.print("Cm = ");
  Serial.println(cm);
  Serial.println();
  Serial.print(" \n | AcX = "); Serial.println(AcX);
  Serial.print(" | AcY = "); Serial.println(AcY);
  Serial.print(" | AcZ = "); Serial.println(AcZ);
  Serial.print(" | Tmp = "); Serial.println(Tmp/340.00+36.53);
  Serial.print(" | GyX = "); Serial.println(GyX);
  Serial.print(" | GyY = "); Serial.println(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  Serial.println();*/
  
  delay(333);
}
