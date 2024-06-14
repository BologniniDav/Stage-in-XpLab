unsigned short crv[6]; 

#define HEADSAM 0xFABF



#define CRV_DIST crv[1]
#define CRV_HEAD crv[0]
byte* buff;

long* dist;

long durata, cm;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  

  CRV_HEAD= HEADSAM;
  buff= (byte*) crv;
  
  dist= (long*) &(crv[1]);
}

int mult = 1;
void loop()
{
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  if(Serial.available() > 0){
    mult=Serial.read();
  }
  durata = pulseIn(7, HIGH);
  cm= durata / 58;
  CRV_DIST = cm * mult; 
  //dist[0] = cm; 
  Serial.write(buff, 6);
  delay(100);
  
  Serial.print("Cm = ");
  Serial.println(cm);
  Serial.println();
}
