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
typedef struct Nodo{
  int pos1;
  int pos2;
}Nodo;
List<Nodo> movimientos;
void actualiza()
{
  tiempo++;
  num.mostrar(tiempo);
  if(tiempo == 11){
    tiempo = 0; digitalWrite(50,HIGH); delay(300); digitalWrite(50,LOW);
    Nodo *n = new Nodo;
    n->pos1 = 0;
    n->pos2 = 0;
    movimientos.Add(*n);
    //movimientos.Add(obtenerValor1());
    muestraNumero(movimientos.Count());
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
  interpreta_matriz(matrizTrans, 1000);
   if(digitalRead(btnA)==HIGH && digitalRead(btnB) == HIGH)
   {
     //SI REGRESA O ESTA ESPERANDO A PODER EJECUTAR LOS MOVIMIENTOS SI HAY
     num.mostrar(0);
     correLetra(A, 0);
     correLetra(N7,5);
     interpreta_matriz(matrizTrans, 500);
   }
   if(digitalRead(btnA)== HIGH && digitalRead(btnB) == LOW)
   {
     //SI HAY MOVIMIENTOS EN LA LISTA LOS MOSTRAREMOS
     if(movimientos.Count()>0)
     {
       for(int x = 0; x < movimientos.Count(); x++)
       {
         correLetra(BLANK, 0);
         correLetra(BLANK, 5);
         num.mostrar(x);
         delay(3000);
       }
       movimientos.Clear();
     }
     //DE LO CONTRARIO NO HAREMOS NADA
   }
   if(digitalRead(btnA)==LOW)
   {
     //DEBERIA DE EMPEZAR A GUARDAR LOS MOVIMIENTOS
     tm.update();
   }
   
}


