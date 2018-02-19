#include <Servo.h>

Servo servo1;
int S1Escritura = 6;
int S1VCC = 7;
int P1Lectura = A2;

Servo servo2;
int S2Escritura = 4;
int S2VCC = 5;
int P2Lectura = A1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(S1Escritura);
  pinMode(S1VCC, OUTPUT);
  digitalWrite(S1VCC, HIGH);
  Serial.begin(9600);

  servo2.attach(S2Escritura);
  pinMode(S2VCC, OUTPUT);
  digitalWrite(S2VCC,LOW);
  //servo1.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(P1Lectura);
  //int angulo = map(val,0,1023,180,0);
  val = map(val, 0, 1023, 0, 180); 
  Serial.println(val,DEC);
  servo1.write(160);
  //servo2.write(160);
  
  delay(2000);  
}
