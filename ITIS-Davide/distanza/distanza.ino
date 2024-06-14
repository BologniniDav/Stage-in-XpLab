unsigned short crv[10];
#define HEADSAM 0xFAFB

#define CRV_HEAD crv[0]
byte* buff;

long* dist;

#define trigPin 6
#define echoPin 7
#define trigPin2 8
#define echoPin2 9

long durata, cm;
long durata2, cm2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  CRV_HEAD= HEADSAM;
  buff= (byte*) crv;
  
  dist= (long*) &(crv[1]);
}

int mult = 1;
void loop()
{
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin2, LOW);
  if(Serial.available() > 0){
    mult=Serial.read();
  }
  durata = pulseIn(echoPin, HIGH);
  durata2 = pulseIn(echoPin2, HIGH);
  cm=durata / 58;
  cm2=durata2 / 58;
  crv[3] = cm; 
  crv[7] = cm2;
  Serial.write(buff, 10);
  delay(100);
  Serial.print("Cm = ");
  Serial.println(cm);
  Serial.println();
}
