#ifndef LCDD_h
#define LCDD_h

#include "Arduino.h"
#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>


class LCDD
{
	public:
		LCDD( int a);
    void proDisp(int cantidad);
    void setHora(int hora, int minutos);
    void solManual(int cantidad);
    void solAuto(int cantidad);
    void verLCD(); 
      
   private:
      //LiquidCrystal pantalla(7, 8, 9, 10, 11, 12);
      time_t  t;
};

#endif 
