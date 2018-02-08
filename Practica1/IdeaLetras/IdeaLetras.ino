
//PUERTOS DEFINIDOS ANTERIOR MENTE EN EL ARDUINO MEGA Y DIAGRAMA DE COMBINACIONES
//                   5,  2,  7,  1,  e,  8,  c,  h
int portColums[] = {30, 24, 34, 22, 31, 36, 27, 37};

//                 a,  b,  f,  6,  g,  4,  3,  d
int portRows[] = {23, 25, 33, 32, 35, 28, 26, 29};

//VARIABLE QUE IDENTIFICA LA POSICION
int posicion;
//VARIABLE QUE IDENTIFICA LA MODALIDAD
int modo;
//VARIABLE QUE MANEJA LA VELOCIDA
int velocidad;

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
  Serial.begin(9600);
  init_setup();
  setColumns();
  setRows();
  pinMode(50,INPUT);
  int posicion = -4;
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for(int x = -4; x<8; x++)
  {
    correLetra_Derecha(A,x);
    delay(5);
  }
  delay(5);
  for(int x = 11; x>=0; x--)
  {
    correLetra_Izquierda(A,x);
    delay(5);
  }*/
  if(digitalRead(50)==HIGH)
  {
    correLetra_Derecha(P,posicion-1);
    posicion++;
    if(posicion>8 || posicion< -4)
    {
      posicion = -4;
    }
  }
  else
  {
    int pos2 = posicion - 5;
    clearMatrix();
    correLetra_Izquierda(P,posicion);
    posicion--;
    if(posicion>=11 || posicion < 0)
    {
      posicion = 11;
    }
   /* 
    correLetra_Izquierda(P,pos2);
    pos2--;
    if(pos2>=11 || pos2 < 0)
    {
      pos2 = 11;
    }*/
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

//CORRE LA LETRA HACIA LA DERECHA
void correLetra_Derecha(int letra[4][8], int colinicio)
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

//CORRE LA LETRA HACIA LA IZQUIERDA
void correLetra_Izquierda(int letra[4][8], int colinicio)
{
  
  int colfinal = colinicio-4;
  if(colfinal <= 0)
  {
    colfinal = 0;
  }
  for(int col = colinicio; col >= colfinal; col--)
  {
    
    for(int fil = 0; fil < 8; fil++)
    {
      matrizTrans[col][fil] = letra[colinicio-col][fil];
    }
    
  }
  interpreta_matriz(matrizTrans);
}

//PARA VER LA MATRIZ EN EL PUERTO SERIAL
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

//VACIA LA MATRIZ
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

