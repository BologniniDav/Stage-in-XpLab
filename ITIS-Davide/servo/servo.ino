#include <Servo.h> // include la Libreria Servo.h

Servo myservo;  // crea l'oggetto di tipo Servo, myservo sarà l'oggetto su cui opererai
int pos = 0;    // inizializza una variabile di tipo intero pos il cui valore sarà la posizione da impartire al servo

void setup() {

  // lega l'oggetto myservo al pin a cui abbiamo collegato il nostro servo, in questo caso il pin 8
}


void loop() {
  for (pos = 0; pos < 180; pos ++) // imposta un ciclo con valori che vanno da 0 a 180, sarano i gradi di spostamento del nostro servo
  {
    analogWrite(5,pos);              // con il metodo write() passi all'oggetto myservo la posizione che deve raggiungere,
    // il servo si sposterà gradualmente dalla sua posizione 0° alla posizione 180°
                      // imposta un ritardo di 15 millesimi di secondo per ogni ciclo del for.
    // Più sarà alto il ritardo più il servo sarà lento.
  }
 delay(5000);

 for (pos = 180; pos < 360; pos ++) // In questo caso imposta un ciclo con valori che vanno da 180 a 0
  {
    analogWrite(5,pos);
    delay(50);
  }


   }
