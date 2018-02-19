//#include "ManejoServo.h"
#include "Matriz.h"
#include "Numero.h"
#include "Timer.h"
#include "Servo.h"
#include "ListLib.h"
/////////////DEFINICION PARA BOTONES//////////////////
int btnA = 49;
int btnB = 48;
void setting_buttons()
{
  pinMode(btnA, INPUT);
  pinMode(btnB, INPUT);
}
//////////////////////////////////////////////////////

/////////////DEFINICION DE LA MATRIZ//////////////////
void setting_matrix()
{
  init_setup();
  setColumns();
  setRows();
}
//////////////////////////////////////////////////////

////////////DEFINICION DEL DISPLAY////////////////////
Numero num(38,40,42,44,39,41,43,45);
//////////////////////////////////////////////////////

////////////DEFINICION DE SERVOMOTORES///////////////
//---------------------------------------------------
Servo servo1;
int ser1VCC = 7;
int ser1Pin = 6;
int analogoSer1 = A1;
void setting_motor1()
{
  pinMode(ser1VCC, OUTPUT);
  servo1.attach(ser1Pin);
  digitalWrite(ser1VCC, LOW);
}
int obtenerValor1()
{
  int val = analogRead(analogoSer1);
  int angulo = map(val,0,1023,180,0);
  int ang = calcula_movimiento(angulo);
  Serial.println(ang);
  return ang;
}
//---------------------------------------------------
int calcula_movimiento(int angulo)
{
  
  int res = 240.39708-(1.42636*angulo);
  if(res < 9){return 10;}
  if(res > 155) {return 155;}
  return res;
}
//---------------------------------------------------
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
Timer tm;
int tiempo;
typedef struct nodo{
  int valMotor1;
  int valMotor2;
}nodo;
List<int> movimientos;
void actualiza()
{
  tiempo++;
  if(tiempo == 11){
    tiempo = 0; digitalWrite(50,HIGH); delay(300); digitalWrite(50,LOW);
    movimientos.Add(obtenerValor1());
    num.mostrar(movimientos.Count());
  }
}
/////////////////////////////////////////////////////

void setup() {
  setting_motor1();
  setting_buttons();
  setting_matrix();
  tm.every(1000,actualiza);
  pinMode(50, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   if(digitalRead(btnA)==HIGH && digitalRead(btnB) == HIGH)
   {
     correLetra(A, 0);
     correLetra(N7,5);
     interpreta_matriz(matrizTrans, 500);
   }
   if(digitalRead(btnA)==LOW)
   {
     //DEBERIA DE EMPEZAR A GUARDAR LOS MOVIMIENTOS
   }
   
}


