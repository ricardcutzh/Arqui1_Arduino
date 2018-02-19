#ifndef Matriz_h
#define Matriz_h
#include "Arduino.h"
#include "Letras.h"
void init_setup();
void setRows();
void setColumns();
void clearMatrix();
void configurar_matriz();
void interpreta_matriz(int matriz[8][8], int retardo);
void correLetra(int letra[4][8], int colinicio);
void muestraNumero(int num);
//MATRIZ GLOBAL
int matrizTrans[8][8] =
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

//PUERTOS DEFINIDOS ANTERIOR MENTE EN EL ARDUINO MEGA Y DIAGRAMA DE COMBINACIONES
//                   5,  2,  7,  1,  e,  8,  c,  h
int portColums[] = {30, 24, 34, 22, 31, 36, 27, 37};

//                 a,  b,  f,  6,  g,  4,  3,  d
int portRows[] = {23, 25, 33, 32, 35, 28, 26, 29};

void configurar_matriz()
{
    init_setup();
    setColumns();
    setRows();
}

void clearMatrix()
{
  for (int col = 0; col < 8; col++)
  {
    for (int fil = 0; fil < 8; fil++)
    {
      matrizTrans[col][fil] = 0;

    }
  }
}

void init_setup()
{
  for (int x = 22; x < 38; x++)
  {
    pinMode(x, OUTPUT);
  }
}

//METODO QUE SE ENCARGA DE PONER LAS FILAS COLUMNAS EN APAGADOS
void setColumns()
{
  for (int x = 0; x < 8; x++)
  {
    digitalWrite(portColums[x], LOW);
  }
}

//METODO QUE SE ENCARGA DE PONER LAS FILAS EN APAGADOS
void setRows()
{
  for (int x = 0; x < 8; x++)
  {
    digitalWrite(portRows[x], HIGH);
  }
}

void interpreta_matriz(int matriz[8][8], int retardo)
{
  
  for (int x = 0; x < retardo; x++)
  {
    for (int col = 0; col < 8; col++)
    {
      digitalWrite(portColums[col], HIGH);
      for (int fil = 0; fil < 8; fil++)
      {
        if (matriz[col][fil] == 1)
        {
          digitalWrite(portRows[fil], LOW);
        }
      }
      digitalWrite(portColums[col], LOW);
      setRows();
    }
  }
  //comentar si es necesario
  //clearMatrix();
}

//CORRE LA LETRA HACIA LA DERECHA
void correLetra(int letra[4][8], int colinicio)
{
  //clearMatrix();
  if (!(colinicio < -4))
  {
    int colfinal = colinicio + 4;
    if (colfinal > 8)
    {
      colfinal = 8;
    }
    for (int col = colinicio; col < colfinal; col++)
    {

      for (int fil = 0; fil < 8; fil++)
      {
        matrizTrans[col][fil] = letra[col - colinicio][fil];
      }
    }
  }
}

void muestraNumero(int num)
{
  if(num == 0){
    correLetra(P0, 0);
    correLetra(P0, 4);
    return;
  }
  if(num == 1){
    correLetra(P0, 0);
    correLetra(P1, 4);
    return;
  }
  if(num == 2){
    correLetra(P0, 0);
    correLetra(P2, 4);
    return;
  }
  if(num == 3){
    correLetra(P0, 0);
    correLetra(P3, 4);
    return;
  }
  if(num == 4){
    correLetra(P0, 0);
    correLetra(P4, 4);
    return;
  }
  if(num == 5){
    correLetra(P0, 0);
    correLetra(P5, 4);
    return;
  }
  if(num == 6){
    correLetra(P0, 0);
    correLetra(P6, 4);
    return;
  }
  if(num == 7){
    correLetra(P0, 0);
    correLetra(P7, 4);
  }
  if(num == 8){
    correLetra(P0, 0);
    correLetra(P8, 4);
    return;
  }
  if(num == 9){
    correLetra(P0, 0);
    correLetra(P9, 4);
    return;
  }
  if(num == 10){
    correLetra(P1, 0);
    correLetra(P0, 4);
    return;
  }
  if(num == 11){
    correLetra(P1, 0);
    correLetra(P1, 4);
    return;
  }
  if(num == 12){
    correLetra(P1, 0);
    correLetra(P2, 4);
    return;
  }
  if(num == 13){
    correLetra(P1, 0);
    correLetra(P3, 4);
    return;
  }
  if(num == 14){
    correLetra(P1, 0);
    correLetra(P4, 4);
    return;
  }
  if(num == 15){
    correLetra(P1, 0);
    correLetra(P5, 4);
    return;
  }
  if(num == 16){
    correLetra(P1, 0);
    correLetra(P6, 4);
    return;
  }
  if(num == 17){
    correLetra(P1, 0);
    correLetra(P7, 4);
    return;
  }
  if(num == 18){
    correLetra(P1, 0);
    correLetra(P8, 4);
    return;
  }
  if(num == 19){
    correLetra(P1, 0);
    correLetra(P9, 4);
    return;
  }
  if(num == 20){
    correLetra(P2, 0);
    correLetra(P0, 4);
    return;
  }
  if(num == 21){
    correLetra(P2, 0);
    correLetra(P1, 4);
    return;
  }
  if(num == 22){
    correLetra(P2, 0);
    correLetra(P2, 4);
    return;
  }
  if(num == 23){
    correLetra(P2, 0);
    correLetra(P3, 4);
    return;
  }
  if(num == 24){
    correLetra(P2, 0);
    correLetra(P4, 4);
    return;
  }
  if(num == 25){
    correLetra(P2, 0);
    correLetra(P5, 4);
    return;
  }
  if(num == 26){
    correLetra(P2, 0);
    correLetra(P6, 4);
    return;
  }
  if(num == 27){
    correLetra(P2, 0);
    correLetra(P7, 4);
    return;
  }
  if(num == 28){
    correLetra(P2, 0);
    correLetra(P8, 4);
    return;
  }
  if(num == 29){
    correLetra(P2, 0);
    correLetra(P9, 4);
    return;
  }
  if(num == 30){
    correLetra(P3, 0);
    correLetra(P0, 4);
    return;
  }
  if(num == 31){
    correLetra(P3, 0);
    correLetra(P1, 4);
    return;
  }
  if(num == 32){
    correLetra(P3, 0);
    correLetra(P2, 4);
    return;
  }
  if(num == 33){
    correLetra(P3, 0);
    correLetra(P3, 4);
  }
  if(num == 34){
    correLetra(P3, 0);
    correLetra(P4, 4);
    return;
  }
  if(num == 35){
    correLetra(P3, 0);
    correLetra(P5, 4);
    return;
  }
  if(num == 36){
    correLetra(P3, 0);
    correLetra(P6, 4);
    return;
  }
  if(num == 37){
    correLetra(P3, 0);
    correLetra(P7, 4);
    return;
  }
  if(num == 38){
    correLetra(P3, 0);
    correLetra(P8, 4);
    return;
  }
  if(num == 39){
    correLetra(P3, 0);
    correLetra(P9, 4);
    return;
  }
  if(num == 40){
    correLetra(P4, 0);
    correLetra(P0, 4);
    return;
  }
  if(num == 41){
    correLetra(P4, 0);
    correLetra(P1, 4);
    return;
  }
  if(num == 42){
    correLetra(P4, 0);
    correLetra(P2, 4);
    return;
  }
  if(num == 43){
    correLetra(P4, 0);
    correLetra(P3, 4);
    return;
  }
  if(num == 44){
    correLetra(P4, 0);
    correLetra(P4, 4);
    return;
  }
  if(num == 45){
    correLetra(P4, 0);
    correLetra(P5, 4);
    return;
  }
  if(num == 46){
    correLetra(P4, 0);
    correLetra(P6, 4);
    return;
  }
  if(num == 47){
    correLetra(P4, 0);
    correLetra(P7, 4);
    return;
  }
  if(num == 48){
    correLetra(P4, 0);
    correLetra(P8, 4);
    return;
  }
  if(num == 49){
    correLetra(P4, 0);
    correLetra(P9, 4);
    return;
  }
  if(num == 50){
    correLetra(P5, 0);
    correLetra(P0, 4);
    return;
  }
}

#endif