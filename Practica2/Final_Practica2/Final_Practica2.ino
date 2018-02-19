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
int S1Escritura = 6;
int P1Lectura = A2;
int devuelveAngulo1()
{
  int val = analogRead(P1Lectura);
  val = map(val, 0, 1023, 0, 180);
  if(val < 16)
  {
    val = 16;
  }
  int angulo = -18.62184+(1.44706*val);
  if(angulo < 5){ angulo = 5;}
  if(angulo > 160){ angulo = 160;}
  return angulo;
}
//---------------------------------------------------
Servo servo2;
int S2Escritura = 4;
int P2Lectura = A1;
int devuelveAngulo2()
{
  int val = analogRead(P2Lectura);
  val = map(val, 0, 1023, 0, 180);
  if(val < 2)
  {
    val = 2;
  }
  int angulo = -2.87951+(1.40329*val);
  if(angulo < 0){ angulo = 0;}
  if(angulo > 160){ angulo = 160;}
  return angulo;
}
//--------------------------------------------------
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
    n->pos1 = devuelveAngulo1();
    n->pos2 = devuelveAngulo2();
    movimientos.Add(*n);
    //movimientos.Add(obtenerValor1());
    muestraNumero(movimientos.Count());
  }
}
/////////////////////////////////////////////////////

void setup() {
  setting_buttons();
  setting_matrix();
  tm.every(1000,actualiza);
  pinMode(50, OUTPUT);
  Serial.begin(9600);
  llevaAHome();
}

void loop() {
  interpreta_matriz(matrizTrans, 1000);
   if(digitalRead(btnA)==HIGH && digitalRead(btnB) == HIGH)
   {
     //SI REGRESA O ESTA ESPERANDO A PODER EJECUTAR LOS MOVIMIENTOS SI HAY
     llevaAHome();
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
       //ENCIENDO LOS SERVOS
       servo1.attach(S1Escritura);
       servo2.attach(S2Escritura);
       for(int x = 0; x < movimientos.Count(); x++)
       {
         correLetra(BLANK, 0);
         correLetra(BLANK, 5);
         num.mostrar(x+1);
         servo1.write(movimientos[x].pos1);
         delay(500);
         servo2.write(movimientos[x].pos2);
         delay(3000);
       }
       movimientos.Clear();
     }
     //DE LO CONTRARIO NO HAREMOS NADA
   }
   if(digitalRead(btnA)==LOW)
   {
     //DEBERIA DE EMPEZAR A GUARDAR LOS MOVIMIENTOS
     servo1.detach();
     servo2.detach();
     tm.update();
   }
   
}

void llevaAHome()
{
  servo1.attach(S1Escritura);
  servo2.attach(S2Escritura);
  servo1.write(0);
  servo2.write(5);
}

