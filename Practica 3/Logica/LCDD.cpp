
#include "LCDD.h"
#include "Arduino.h"

LiquidCrystal pantalla(7, 8, 9, 10, 11, 12);

LCDD::LCDD( int a)
{
    

    pantalla.begin(16, 2);
    // mensaje inicio
    pantalla.print((char)33);
    pantalla.setCursor(1,0);
    pantalla.print("GRUPO 7 A! P0");
    pantalla.setCursor(7, 1);
    pantalla.print("SM00");
    pantalla.setCursor(12,1);
    pantalla.print("SA00");  
    pantalla.setCursor(0, 1); 
    pantalla.print("H");
    //Formato: hora, minutos, segundos, días, mes, año
    setTime(0,0,0,22,2,2018); 
}

void LCDD::proDisp(int cantidad)
{
    pantalla.setCursor(13,0);
    if(cantidad<10)
    {
      pantalla.print(0);
      pantalla.setCursor(14,0);
      pantalla.print(cantidad);
    }
    else
    {
      pantalla.print(cantidad);
    }
}

void LCDD::setHora(int hora, int minutos)
{
    setTime(hora,minutos,0,22,2,2018);
}

void LCDD::solManual(int cantidad)
{
    pantalla.setCursor(9,1);
    if(cantidad<10)
    {
      pantalla.print(0);
      pantalla.setCursor(10,1);
      pantalla.print(cantidad);
    }
    else{
      pantalla.print(cantidad);
    }
}

void LCDD::solAuto(int cantidad)
{
    pantalla.setCursor(14,1);
    if(cantidad<10)
    {
      pantalla.print(0);
      pantalla.setCursor(15,1);
      pantalla.print(cantidad);
    }
    else{
      pantalla.print(cantidad);
    }
}

void LCDD::verLCD()
{
    t = now();
    pantalla.setCursor(1, 1); 
    int hora = hour(t);
    int minuto = minute(t);
    if(hora<10)
    {
      pantalla.print(0);
      pantalla.setCursor(2,1);
      pantalla.print(hora);
    }else
    {
      pantalla.print(hora);
    }
    pantalla.setCursor(3, 1); 
    pantalla.print(":");
    if(minuto<10)
    {
      pantalla.print(0);
      pantalla.setCursor(5,1);
      pantalla.print(minuto);
    }else
    {
      pantalla.print(minuto);
    }
    
}
