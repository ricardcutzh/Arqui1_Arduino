#include"ManejoServo.h"

ManejoServo::ManejoServo(int pinVCC, int pinServo, int PinAnalogo, Servo serv)
{
    this->pinVCC = pinVCC;
    pinMode(pinVCC, OUTPUT);
    this->pinServo = pinServo;
    pinMode(this->pinServo, OUTPUT);
    this->PinAnalogo = PinAnalogo;
    pinMode(PinAnalogo, INPUT);
    this->servo = serv;
    this->servo.attach(pinServo);
}

int ManejoServo::obetenerAngulo()
{
    int val = analogRead(this->PinAnalogo);
    return map(val,0,1023,180,0);
}

void ManejoServo::mueveServo_angulo(int angulo)
{
    this->servo.write(angulo);
}

void ManejoServo::apagaServoMotor()
{
    digitalWrite(this->pinVCC, LOW);
}

void ManejoServo::enciendeServoMotor()
{
    digitalWrite(this->pinVCC, HIGH);
}
