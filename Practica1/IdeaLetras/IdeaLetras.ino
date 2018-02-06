
//PUERTOS DEFINIDOS ANTERIOR MENTE EN EL ARDUINO MEGA Y DIAGRAMA DE COMBINACIONES
//                   5,  2,  7,  1,  e,  8,  c,  h
int portColums[] = {30, 24, 34, 22, 31, 36, 27, 37};

//                 a,  b,  f,  6,  g,  4,  3,  d
int portRows[] = {23, 25, 33, 32, 35, 28, 26, 29};

//MATRIZ GLOBAL
int matrizTrans[8][8] = 
{
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}  
};
//MATRIZ DE PRUEBA
// COL | FILA
int A[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,1,0,1,0},
              {0,0,0,0,1,0,1,0},
              {0,1,1,1,1,1,1,0}
            };
int C[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,1,0,0,1,1,0}
            };
int P[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,1,0,1,0},
              {0,0,0,0,1,0,1,0},
              {0,0,0,0,0,1,0,0}
            };
int T[4][8] = {
              {0,0,0,0,0,1,1,0},
              {0,1,1,1,1,1,1,0},
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,0,1,1,0}
            };
int N1[4][8] = {
              {0,1,0,0,1,0,0,0},
              {0,1,0,0,0,1,0,0},
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,0,0}
            };

//Matriz reducida

int MA[4][6]={
              {1,1,1,1,1,1},
              {0,0,0,1,0,1},
              {0,0,0,1,0,1},
              {1,1,1,1,1,1}
            };

void setup() {
  // put your setup code here, to run once:
  init_setup();
  setColumns();
  setRows();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /*interpreta_matriz_minima(3,MA);
  delay(500);
  interpreta_matriz_minima(1,MA);*/
  //delay(500);
  //interpreta_matriz(A);
  for(int x = 0; x<8; x++)
  {
    correLetra(A,x);
    delay(5);
  }
  delay(5);
  for(int x = 0; x<8; x++)
  {
    correLetra(N1,x);
    delay(5);
  }
  delay(5);
  for(int x = 0; x<8; x++)
  {
    correLetra(C,x);
    delay(5);
  }
}

/**************************************************************/

//METODO QUE SE ENCARGA DE INTERPRETAR UNA MATRIZ QUE DEFINE LA SALIDA DE LOS LEDS
void interpreta_matriz(int matriz[8][8])
{
  for(int x = 0;x <1000; x++)
  {
    for(int col = 0; col < 8; col++)
    {
      digitalWrite(portColums[col],HIGH);
      for(int fil = 0; fil < 8; fil++)
      {
        if(matriz[col][fil]==1)
        {
          digitalWrite(portRows[fil], LOW);
        }
      }
    //delay(5);
    digitalWrite(portColums[col],LOW);
    setRows();
    //delay(5000);
    }
  }
}

void correLetra(int letra[4][8], int colinicio)
{
  clearMatrix();
  int colfinal = colinicio+4;
  if(colfinal > 8)
  {
    colfinal = 8;
  }
  for(int col = colinicio; col < colfinal; col++)
  {
    
    for(int fil = 0; fil < 8; fil++)
    {
      matrizTrans[col][fil] = letra[col-colinicio][fil];
    }
  }
  interpreta_matriz(matrizTrans);
}

void printMatrix()
{
  Serial.begin(9600);
  for(int col = 0; col < 8; col++)
  {
    for(int fil = 0; fil < 8; fil++)
    {
      Serial.print(matrizTrans[col][fil]);
      Serial.print(" ");
    }
    Serial.println("");
  }
  Serial.println("---------------------------------------------");
}

void clearMatrix()
{
  for(int col = 0; col < 8; col++)
  {
    for(int fil = 0; fil < 8; fil++)
    {
      matrizTrans[col][fil] = 0;
      
    }
  }
}

//Metodo que interpreta la matriz minima, y recibe como parametro la columna inicial

void interpreta_matriz_minima(int columnaInicio,int matriz[4][6])
{
  for(int x = 0;x <2000; x++)
  {
    int ancho=4;
/*
    if(columnaInicio+4>8){
      ancho=8-columnaInicio;
      }*/
      
  for(int col = columnaInicio; col < ancho; col++)
  {
    digitalWrite(portColums[col],HIGH);
    for(int fil = 1; fil < 7; fil++)
    {

      if(matriz[col][fil]==1)
      {
        digitalWrite(portRows[fil], LOW);
      }
    }
    //delay(5);
    digitalWrite(portColums[col],LOW);
    setRows();
    //delay(5000);
  }
  }
  
}



//METODO QUE SE ENCARGA DE SETEAR DE INICIO LA MODALIDAD DE LOS PINES A UTILIZAR
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

/**************************************************************/

