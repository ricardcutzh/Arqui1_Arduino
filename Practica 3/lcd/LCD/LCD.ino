#include<string.h>
#include<stdlib.h>
#include"LCDD.h"
#include"Timer.h"
#include <Servo.h>
Servo servo1;
////////////////
int pinServo = 6;
////////////////

LCDD lcd( 4 ); 

////////////////
int stock;
int hora;
int minuto;
int cant_auto;
int cant_manu;
///////////////
Timer tm;
//time_t  t; 
void setup() {
  // put your setup code here, to run once:
  tm.every(20000,actualiza_hora);
  int stock = 0;
  int hora = 0;
  int minuto = 0;
  int cant_auto = 0;
  int cant_manu = 0;
  Serial.begin(9600);
  servo1.attach(pinServo);
}

void loop() {
  // put your main code here, to run repeatedly:
   tm.update();
   if(Serial.available())
   {
      String cadena = Serial.readString();
      char ca[5];
      cadena.toCharArray(ca,5);
      if(ca[0]==109)//Manunal
      {
        cant_manu++;
        char temporal[2];
        temporal[0] = ca[2];
        temporal[1] = ca[3];
        manual(temporal);
      }
      else if(ca[0]==115)//Stock
      {
        char temporal[2];
        temporal[0] = ca[2];
        temporal[1] = ca[3];
        set_stock(temporal);
      }
      else if(ca[0]==97)//Automatica
      {
        cant_auto++;
        char temporal[2];
        temporal[0] = ca[2];
        temporal[1] = ca[3];
        automatica(temporal);
      }
      else if(ca[0]==72)//HORA
      {
        char temporal[2];
        temporal[0] = ca[2];
        temporal[1] = ca[3];
        set_hour(temporal);
        Serial.println("SI SETIE HORA");
        lcd.setHora(hora, minuto);
        lcd.verLCD();
      }
      else if(ca[0]==77)//MINUTOS
      {
        char temporal[2];
        temporal[0] = ca[2];
        temporal[1] = ca[3];
        set_minutes(temporal);
        
        lcd.setHora(hora, minuto);
        lcd.verLCD();
      }
   }
}

/////////////////////////////////////////////////////////
void manual(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  int cantidad = temp.toInt();
  stock = stock - cantidad;
  despachar(cantidad);
  Serial.print("Manual: ");
  Serial.println(cantidad);
  lcd.solManual(cant_manu);
  actualizaElStock();
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void automatica(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  int cantidad = temp.toInt();
  stock = stock - cantidad;
  despachar(cantidad);
  Serial.print("Automatica: ");
  Serial.println(cantidad);
  lcd.solAuto(cant_auto);
  actualizaElStock();
}
////////////////////////////////////////////////////////
void set_stock(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  stock = temp.toInt();
  Serial.print("Setting Stock: ");
  Serial.println(stock);
  lcd.proDisp(stock);
}
///////////////////////////////////////////////////////
void set_minutes(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  minuto = temp.toInt();
  
}
///////////////////////////////////////////////////////
void set_hour(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  hora = temp.toInt();
}
///////////////////////////////////////////////////////
void actualiza_hora()
{
  lcd.verLCD();
}
///////////////////////////////////////////////////////
void actualizaElStock()
{
  lcd.proDisp(stock);
}
///////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////


