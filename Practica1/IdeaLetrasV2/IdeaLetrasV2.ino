
//PUERTOS DEFINIDOS ANTERIOR MENTE EN EL ARDUINO MEGA Y DIAGRAMA DE COMBINACIONES
//                   5,  2,  7,  1,  e,  8,  c,  h
int portColums[] = {30, 24, 34, 22, 31, 36, 27, 37};

//                 a,  b,  f,  6,  g,  4,  3,  d
int portRows[] = {23, 25, 33, 32, 35, 28, 26, 29};

//NUMERO DE LETRAS
int cantidad;

//VARIABLES ENCARGADAS DE LLEVAR LA POSICION DE LOS LIMITES
int posinicio, posfin;

//VARIABLE QUE IDENTIFICA LA POSICION
int posicion;
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
int BLANK[4][8] = {
              {0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0}
            };
int AST[4][8] = {
              {0,0,1,0,1,0,1,0},
              {0,0,0,1,1,1,0,0},
              {0,0,0,1,1,1,0,0},
              {0,0,1,0,1,0,1,0}
            };
/*----------------------------*/
int A[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,1,0,1,0},
              {0,0,0,0,1,0,1,0},
              {0,1,1,1,1,1,1,0}
            };
/*----------------------------*/
int B[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,1,0,1,0},
              {0,1,0,0,1,0,1,0},
              {0,0,1,1,0,1,1,0}
            };
/*----------------------------*/
int C[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,1,0,0,1,0,0}
            };
/*----------------------------*/
int D[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,0,0,0,0,1,0},
              {0,0,1,1,1,1,0,0}
            };
/*----------------------------*/           
int E[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,1,0,1,0},
              {0,1,0,0,1,0,1,0},
              {0,1,0,0,0,0,1,0}
            };
/*----------------------------*/           
int F[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,1,0,1,0},
              {0,0,0,0,1,0,1,0},
              {0,0,0,0,0,0,1,0}
            };
/*----------------------------*/           
int G[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,0,0,1,0,1,0},
              {0,1,1,1,1,0,1,0}
            };
/*----------------------------*/           
int H[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,1,0,0,0},
              {0,0,0,0,1,0,0,0},
              {0,1,1,1,1,1,1,0}
            };
/*----------------------------*/           
int I[4][8] = {
              {0,1,0,0,0,0,1,0},
              {0,1,1,1,1,1,1,0},
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,1,0}
            };

/*----------------------------*/
int J[4][8] = {
              {0,1,1,1,0,0,1,0},
              {0,1,0,0,0,0,1,0},
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,0,0,1,0}
            };
/*----------------------------*/
int K[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,1,1,0,0,0},
              {0,0,1,0,0,1,0,0},
              {0,1,0,0,0,0,1,0}
            };
/*----------------------------*/
int L[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,0,0},
              {0,1,0,0,0,0,0,0},
              {0,1,0,0,0,0,0,0}
            };
/*----------------------------*/
int M[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,0,1,0,0},
              {0,0,0,0,0,1,0,0},
              {0,1,1,1,1,1,1,0}
            };
/*----------------------------*/
int N[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,1,0,0,0},
              {0,0,0,1,0,0,0,0},
              {0,1,1,1,1,1,1,0}
            };
/*----------------------------*/           
int O[4][8] = {
              {0,0,1,1,1,1,0,0},
              {0,1,0,0,0,0,1,0},
              {0,1,0,0,0,0,1,0},
              {0,0,1,1,1,1,0,0}
            };
/*----------------------------*/           
int P[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,1,0,0,1,0},
              {0,0,0,1,0,0,1,0},
              {0,0,0,0,1,1,0,0}
            };
/*----------------------------*/           
int Q[4][8] = {
              {0,0,1,1,1,1,0,0},
              {0,1,0,0,0,0,1,0},
              {0,1,1,0,0,0,1,0},
              {0,1,1,1,1,1,0,0}
            };
/*----------------------------*/           
int R[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,0,1,0,0,1,0},
              {0,0,1,1,0,0,1,0},
              {0,1,0,0,1,1,0,0}
            };
/*----------------------------*/           
int S[4][8] = {
              {0,0,1,0,0,1,0,0},
              {0,1,0,0,1,0,1,0},
              {0,1,0,0,1,0,1,0},
              {0,0,1,1,0,0,1,0}
            };
/*----------------------------*/
int T[4][8] = {
              {0,0,0,0,0,1,1,0},
              {0,1,1,1,1,1,1,0},
              {0,1,1,1,1,1,1,0},
              {0,0,0,0,0,1,1,0}
            };
/*----------------------------*/
int U[4][8] = {
              {0,0,1,1,1,1,1,0},
              {0,1,0,0,0,0,0,0},
              {0,1,0,0,0,0,0,0},
              {0,0,1,1,1,1,1,0}
            };
/*----------------------------*/
int V[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,1,0,0,0,0,0,0},
              {0,1,0,0,0,0,0,0},
              {0,1,1,1,1,1,1,0}
            };
/*----------------------------*/
int W[4][8] = {
              {0,1,1,1,1,1,1,0},
              {0,0,1,0,0,0,0,0},
              {0,0,1,0,0,0,0,0},
              {0,1,1,1,1,1,1,0}
            };
/*----------------------------*/
int Y[4][8] = {
              {0,0,0,0,0,1,1,0},
              {0,0,0,0,1,0,0,0},
              {0,1,1,1,1,0,0,0},
              {0,0,0,0,0,1,1,0}
            };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_setup();
  setColumns();
  setRows();
  pinMode(50,INPUT);
  cantidad = 10;
  definirLimites(cantidad,digitalRead(50));
  posicion = posinicio;
}

void loop() {
  // put your main code here, to run repeatedly:
  int dir = digitalRead(50);
  if(dir == HIGH)
  {
    definirLimites(cantidad,dir);
    posicion++;
    if(posicion >= posfin)
    {
      posicion = posinicio;
    }
  }
  else
  {
    definirLimites(cantidad,dir);
    posicion--;
    if(posicion <= posfin)
    {
      posicion = posinicio;
    }
  }
  correLetra(H,posicion);
  correLetra(O,posicion+5);
  correLetra(L,posicion+10);
  correLetra(A,posicion+15);
  correLetra(BLANK,posicion+20);
  correLetra(M,posicion+25);
  correLetra(U,posicion+30);
  correLetra(N,posicion+35);
  correLetra(D,posicion+40);
  correLetra(O,posicion+45);
  interpreta_matriz(matrizTrans);
  clearMatrix();
}

/**************************************************************/

//METODO PARA MOSTRAR
void definirLimites(int numeroLetras, int direccion)
{
  
  int op = -((numeroLetras - 1)*5+4);
  if(direccion == HIGH)//VA LA DERECHA
  {
    //DEFINICION DE LOS LIMITES
    posfin = 8;
    if(numeroLetras == 1)
    {
      posinicio = -4;
    }
    else
    {
      posinicio = op;
    }
    //DEFINICION DE LOS LIMITES
    
  }
  else
  {
    //DEFINICION DE LOS LIMITES
    posinicio = 8;
    if(numeroLetras == 1)
    {
      posfin = -4;
    }
    else
    {
      posfin = op;
    }
    //DEFINICION DE LOS LIMITES
  }
}

//METODO QUE SE ENCARGA DE INTERPRETAR UNA MATRIZ QUE DEFINE LA SALIDA DE LOS LEDS
void interpreta_matriz(int matriz[8][8])
{
  for(int x = 0;x <500; x++)
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
      digitalWrite(portColums[col],LOW);
      setRows();
    }
  }
}

//CORRE LA LETRA HACIA LA DERECHA
void correLetra(int letra[4][8], int colinicio)
{
  //clearMatrix();
  if(!(colinicio < -4))
  {
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
  }
}

//PARA VER LA 
//MATRIZ EN EL PUERTO SERIAL
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

