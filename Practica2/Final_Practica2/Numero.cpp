#include "Arduino.h"
#include "Numero.h"

Numero::Numero(int A,int B,int C,int D,int E,int F,int G, int H)
{
	// Unidad numero A
	_A = A; // A0
	_B = B; // A1
	_C = C; // A2
	_D = D; // A3
	// Decena numero B
	_E = E; // B0
	_F = F; // B1
	_G = G; // B2
	_H = H; // B3
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(H, OUTPUT);
  digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);
	digitalWrite(E, LOW);
	digitalWrite(F, LOW);
	digitalWrite(G, LOW);
	digitalWrite(H, LOW);
}

void Numero::cero()
{
	digitalWrite(_A, LOW);
	digitalWrite(_B, LOW);
	digitalWrite(_C, LOW);
	digitalWrite(_D, LOW);
	
	digitalWrite(_E, LOW);
	digitalWrite(_F, LOW);
	digitalWrite(_G, LOW);
	digitalWrite(_H, LOW);
}

void Numero::uno()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::dos()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::tres()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::cuatro()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::cinco()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::seis()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::siete()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::ocho()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::nueve()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::diez()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::once()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::doce()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::trece()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::catorce()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::quince()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::dieciseis()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::diecisite()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::dieciocho()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::diecinueve()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, LOW);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veinte()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintiuno()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintidos()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintitres()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veinticuatro()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veinticinco()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintiseis()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintisiete()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintiocho()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::veintinueve()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treinta()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintauno()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintados()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintatres()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintacuatro()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintacinco()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintaseis()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);  
}

void Numero::treintasiete()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, HIGH);
  digitalWrite(_C, HIGH);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintaocho()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);
}

void Numero::treintanueve()
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, HIGH);
  
  digitalWrite(_E, HIGH);
  digitalWrite(_F, HIGH);
  digitalWrite(_G, LOW);
  digitalWrite(_H, LOW);  
}

void Numero::cuarenta()
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
  digitalWrite(_C, LOW);
  digitalWrite(_D, LOW);
  
  digitalWrite(_E, LOW);
  digitalWrite(_F, LOW);
  digitalWrite(_G, HIGH);
  digitalWrite(_H, LOW);  
}

void Numero::mostrar(int numero)
{
  switch(numero)
  {
    case 1:
      uno();
      break;
    case 2:
      dos();
      break;
    case 3:
      tres();
      break;
    case 4:
      cuatro();
      break;
    case 5:
      cinco();
      break;
    case 6:
      seis();
      break;
    case 7:
      siete();
      break;
    case 8:
      ocho();
      break;
    case 9:
      nueve();
      break;
    case 10:
      diez();
      break;
    case 11:
      once();
      break;
    case 12:
      doce();
      break;
    case 13:
      trece();
      break;
    case 14:
      catorce();
      break;
    case 15:
      quince();
      break;
    case 16:
      dieciseis();
      break;
    case 17:
      diecisite();
      break;
    case 18:
      dieciocho();
      break;
     case 19:
        diecinueve();
      break;
     case 20:
        veinte();
      break;
      case 21:
        veintiuno();
        break;
      case 22:
        veintidos();
        break;
       case 23:
          veintitres();
          break;
       case 24:
          veinticuatro();
          break;
       case 25:
          veinticinco();
          break;
       case 26:
          veintiseis();
          break;
       case 27:
          veintisiete();
          break;
        case 28:
          veintiocho();
          break;
        case 29:
          veintinueve();
          break;
        case 30:
          treinta();
          break;
        case 31:
            treintauno();
            break;
        case 32:
            treintados();
            break;
        case 33:
            treintatres();
            break;
        case 34:
            treintacuatro();
            break;
        case 35:
            treintacinco();
            break;
        case 36:
            treintaseis();
            break;
        case 37:
            treintasiete();
            break;
        case 38:
            treintaocho();
            break;
        case 39:
            treintanueve();
            break;
        case 40:
            cuarenta();
            break;
  }
  
}


