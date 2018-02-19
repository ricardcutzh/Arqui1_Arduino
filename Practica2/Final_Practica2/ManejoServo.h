#ifndef ManejoServo_h
#define ManejoServo_h
#include "Arduino.h"
#include "Servo.h"

class ManejoServo{
    public:
        int pinVCC;
        int pinServo;
        int PinAnalogo;
        Servo servo;
        ManejoServo(int pinVCC, int pinServo, int PinAnalogo, Servo serv);
        int obetenerAngulo();
        void mueveServo_angulo(int angulo);
        void apagaServoMotor();
        void enciendeServoMotor();
    private:

};

#endif