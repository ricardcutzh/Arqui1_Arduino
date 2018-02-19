#include <Servo.h>

Servo servo1;
int ser = 6;

int controlMotor;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  pinMode(A1, INPUT);
  servo1.attach(ser);
  pinMode(3,INPUT);
  controlMotor = digitalRead(3);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  controlMotor = digitalRead(3);
  if(controlMotor == LOW)
  {
    digitalWrite(2, LOW);
  }
  else{
    digitalWrite(2,HIGH);
  }
  int val = analogRead(A1);
  int angulo = map(val,0,1023,180,0);
  Serial.println(angulo,DEC);
  servo1.write(160);
  delay(2000);

  
}
