#include <Servo.h>

Servo servo6;
Servo servo8;

void setup()
{
  servo6.attach(6);
  servo8.attach(8);
}

int avanti= 180;
int indietro= -180;

void servo_avanti()
{
  servo6.write(avanti);
  servo8.write(avanti);
}

void servo_indietro()
{
  servo6.write(indietro);
  servo8.write(indietro);
}

void loop()
{
  servo_avanti();
  delay(2000);
  servo_indietro();
  delay(2000);
}
