#include <Servo.h>
Servo servo1;

void setup() {
  servo1.attach(6);   // Servo A
}

void despachar(int cantidad){
  for(int z=0; z<cantidad; z++){
    servo1.write(0);
    delay(750);
    servo1.write(150);
    delay(750);
    servo1.write(0);
    delay(750);
  }
}

void loop() {
  
  despachar(3);
  delay(10000000);
}
