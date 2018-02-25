#include<string.h>
#include<stdlib.h>
#include"LCDD.h"
//#include"Timer.h"

////////////////
int stock;
int hora;
int minuto;
int cant_auto;
int cant_manu;
///////////////
///////////////
//Timer tm;
LCDD lcd( 4 );
///////////////

void setup() {
  // put your setup code here, to run once:
  int stock = 0;
  int hora = 0;
  int minuto = 0;
  int cant_auto = 0;
  int cant_manu = 0;
  //Serial.begin(9600);
  //tm.every(20000,actualiza_hora);
  lcd.proDisp(5);
  lcd.solManual(4);
  lcd.solAuto(8);
  lcd.verLCD();
}

void loop() {
  // put your main code here, to run repeatedly:
  //tm.update();
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
    }
    else if(ca[0]==77)//MINUTOS
    {
      char temporal[2];
      temporal[0] = ca[2];
      temporal[1] = ca[3];
      set_minutes(temporal); 
      lcd.setHora(hora, minuto);
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
  /*Serial.print("Manual: ");
  Serial.println(cantidad);*/
  lcd.solManual(cant_manu);
}
/////////////////////////////////////////////////////////
void automatica(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  int cantidad = temp.toInt();
  /*Serial.print("Automatica: ");
  Serial.println(cantidad);*/
  lcd.solAuto(cant_auto);
}
////////////////////////////////////////////////////////
void set_stock(char num[2])
{
  String temp;
  temp.concat(num[0]);
  temp.concat(num[1]);
  stock = temp.toInt();
  /*Serial.print("Setting Stock: ");
  Serial.println(stock);*/
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
