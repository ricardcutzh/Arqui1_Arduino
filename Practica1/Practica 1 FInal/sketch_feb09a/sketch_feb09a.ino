#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
// Declaramos pines a usar para 74ls48
int a = 5;
int b = 4;
int c = 3;
int d = 2;

//Variables para la lectura de la resistencia
int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 100000;
float R2= 0;
float buffer= 0;
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

//VARIABLE QUE LLEVA EL CONTROL DE LA LETRA QUE SE DEBE DE MOSTRAR
int indice;

//TIPO DE MOVIMIENTO
int tipo;
int dir;

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
//MATRIZ DE PRUEBA
// COL | FILA
int BLANK[4][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
int GUION[4][8] = {
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
};
int AST[4][8] = {
  {0, 0, 1, 0, 1, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 1, 0, 1, 0}
};
/*----------------------------*/
int A[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int B[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 0, 1, 1, 0, 1, 1, 0}
};
/*----------------------------*/
int C[4][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0}
};
/*----------------------------*/
int D[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
};
/*----------------------------*/
int E[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0}
};
/*----------------------------*/
int F[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0}
};
/*----------------------------*/
int G[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 1, 1, 1, 0, 1, 0}
};
/*----------------------------*/
int H[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int I[4][8] = {
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0}
};

/*----------------------------*/
int J[4][8] = {
  {0, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0}
};
/*----------------------------*/
int K[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0}
};
/*----------------------------*/
int L[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0}
};
/*----------------------------*/
int M[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int N[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int O[4][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
};
/*----------------------------*/
int P[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 1, 0, 0}
};
/*----------------------------*/
int Q[4][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 0, 0}
};
/*----------------------------*/
int R[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 1, 0, 0, 1, 0},
  {0, 0, 1, 1, 0, 0, 1, 0},
  {0, 1, 0, 0, 1, 1, 0, 0}
};
/*----------------------------*/
int S[4][8] = {
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 0, 1, 1, 0, 0, 1, 0}
};
/*----------------------------*/
int T[4][8] = {
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0}
};
/*----------------------------*/
int U[4][8] = {
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int V[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int W[4][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
/*----------------------------*/
int Y[4][8] = {
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 1, 0}
};
int N1[4][8] = {
  {0, 1, 0, 0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0, 1, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 0}
};
int N7[4][8] = {
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
int N2[4][8] = {
  {0, 1, 1, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 0, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 0, 0}
};
char letras[] = "*TP1-GRUPO-7-SECCION-A*";
int len = sizeof(letras) / sizeof(char);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  indice = 0;
  init_setup();
  setColumns();
  setRows();
  set_display();
  pinMode(50, INPUT);
  pinMode(39, INPUT);
  cantidad = len;
  definirLimites(cantidad, digitalRead(50));
  posicion = posinicio;
}

void loop() {
  // put your main code here, to run repeatedly:
  dir = digitalRead(50);
  tipo = digitalRead(39);
  if (dir == LOW && tipo == LOW) //IZQUIERDA A DERECHA,CORRIDO
  {
    definirLimites(cantidad, dir);
    posicion--;
    if (posicion <= posfin)
    {
      posicion = posinicio;
    }
    int val;
    for (int x = 0; x < len; x++)
    {
      char l = letras[x];
      val = posicion + (x * 5);
      if (val >= 0 && val < 7)
      {
        indice = x;
        selecciona_Letra(l, val);
      }
    }
    int vel = consultarVelocidad();
    interpreta_matriz(matrizTrans, vel);
    clearMatrix();
  }
  else if (dir == LOW && tipo == HIGH) //IZQUIERDA A DERECHA,ESTATICO
  {
    indice++;
    if (indice >= len) {
      indice = 0;
    }
    int vel = consultarVelocidad();
    selecciona_Letra(letras[indice], 2);
    interpreta_matriz(matrizTrans, vel+vel);
    clearMatrix();
  }
  else if (dir == HIGH && tipo == LOW) //DERECHA A IZQUIERDA,CORRIDO
  {
    definirLimites(cantidad, dir);
    posicion++;
    if (posicion >= posfin)
    {
      posicion = posinicio;
    }
    int val;
    for (int x = 0; x < len; x++)
    {
      char l = letras[x];
      val = posicion + (x * 5);
      if (val >= 0 && val < 7)
      {
        indice = x;
        selecciona_Letra(l, val);
      }
    }
    int vel = consultarVelocidad();
    interpreta_matriz(matrizTrans, vel);
    clearMatrix();
  }
  else if (dir == HIGH && tipo == HIGH) //DERECHA A IZQUIERDA,ESTATICO
  {
    clearMatrix();
    indice--;
    if (indice < 0) {
      indice = len;
    }
    int vel = consultarVelocidad();
    selecciona_Letra(letras[indice], 2);
    interpreta_matriz(matrizTrans, vel+vel);
  }
}

/**************************************************************/
void mov_estatico()
{
  define_incremento_est();
  selecciona_Letra(letras[indice], 2);
  interpreta_matriz(matrizTrans, 0);
  clearMatrix();
}
void define_incremento_est()
{
  if (dir == HIGH)
  {
    indice++;
    if (indice >= len) {
      indice = 0;
    }
  }
  else
  {
    indice--;
    if (indice < 0) {
      indice = len;
    }
  }
}
/**************************************************************/
void mov_corrido()
{
  if (dir == HIGH)
  {
    definirLimites(cantidad, dir);
    posicion++;
    if (posicion >= posfin)
    {
      posicion = posinicio;
    }
  }
  else
  {
    definirLimites(cantidad, dir);
    posicion--;
    if (posicion <= posfin)
    {
      posicion = posinicio;
    }
  }
  movimiento();

}
void movimiento()
{

  int val;
  for (int x = 0; x < len; x++)
  {
    char l = letras[x];
    val = posicion + (x * 5);
    if (val >= 0 || val < 7)
    {
      indice = x;
      selecciona_Letra(l, val);
    }
  }
  interpreta_matriz(matrizTrans, 0);
  clearMatrix();
}

//METODO PARA MOSTRAR
void definirLimites(int numeroLetras, int direccion)
{

  int op = -((numeroLetras - 1) * 5 + 4);
  if (direccion == HIGH) //VA LA DERECHA
  {
    //DEFINICION DE LOS LIMITES
    posfin = 8;
    if (numeroLetras == 1)
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
    if (numeroLetras == 1)
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

//PARA VER LA
//MATRIZ EN EL PUERTO SERIAL
void printMatrix()
{
  Serial.begin(9600);
  for (int col = 0; col < 8; col++)
  {
    for (int fil = 0; fil < 8; fil++)
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
  for (int col = 0; col < 8; col++)
  {
    for (int fil = 0; fil < 8; fil++)
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

void selecciona_Letra(char letra, int pos)
{
  if ('-' == letra)
  {
    correLetra(GUION, pos);
    return;
  }
  if ('*' == letra)
  {
    correLetra(AST, pos);
    return;
  }
  if ('A' == letra)
  {
    correLetra(A, pos);
    return;
  }
  if ('B' == letra)
  {
    correLetra(B, pos);
    return;
  }
  if ('C' == letra)
  {
    correLetra(C, pos);
    return;
  }
  if ('D' == letra)
  {
    correLetra(D, pos);
    return;
  }
  if ('E' == letra)
  {
    correLetra(E, pos);
    return;
  }
  if ('F' == letra)
  {
    correLetra(F, pos);
    return;
  }
  if ('G' == letra)
  {
    correLetra(G, pos);
    return;
  }
  if ('H' == letra)
  {
    correLetra(H, pos);
    return;
  }
  if ('I' == letra)
  {
    correLetra(I, pos);
    return;
  }
  if ('J' == letra)
  {
    correLetra(J, pos);
    return;
  }
  if ('K' == letra)
  {
    correLetra(K, pos);
    return;
  }
  if ('L' == letra)
  {
    correLetra(L, pos);
    return;
  }
  if ('M' == letra)
  {
    correLetra(M, pos);
    return;
  }
  if ('N' == letra)
  {
    correLetra(N, pos);
    return;
  }
  if ('O' == letra)
  {
    correLetra(O, pos);
    return;
  }
  if ('P' == letra)
  {
    correLetra(P, pos);
    return;
  }
  if ('Q' == letra)
  {
    correLetra(Q, pos);
    return;
  }
  if ('R' == letra)
  {
    correLetra(R, pos);
    return;
  }
  if ('S' == letra)
  {
    correLetra(S, pos);
    return;
  }
  if ('T' == letra)
  {
    correLetra(T, pos);
    return;
  }
  if ('U' == letra)
  {
    correLetra(U, pos);
    return;
  }
  if ('V' == letra)
  {
    correLetra(V, pos);
    return;
  }
  if ('W' == letra)
  {
    correLetra(W, pos);
    return;
  }
  if ('Y' == letra)
  {
    correLetra(Y, pos);
    return;
  }
  if ('1' == letra)
  {
    correLetra(N1, pos);
    return;
  }
  if ('7' == letra)
  {
    correLetra(N7, pos);
    return;
  }
  if ('2' == letra)
  {
    correLetra(N2, pos);
    return;
  }
}
void set_display()
{
  //Definir Pines de Display
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}
/*************************DISPLAY*********************************/
void numeroUno(){
//Numero 1
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void numeroDos(){
 //numero 2
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void numeroTres(){
//Numero 3 
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);  
}
void numeroCuatro(){
//Numero 4
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);  
}
void numeroCinco(){
//Numero 5
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);  
}

/**************************************************************/
int consultarVelocidad()
{
  //***Procedimiento para capturar el potenciometro****
  int retorno=0;
  raw= analogRead(analogPin);
  if(raw){
    buffer= raw * Vin;
    Vout= (buffer)/1024.0;
    buffer= (Vin/Vout) -1;
    R2= R1 * buffer;
    
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R2: ");
    Serial.println(R2);
    if (R2<100000){
      retorno=1000;
      numeroUno();
    }else if(R2<200000){
      retorno = 800;
      numeroDos();
    }else if(R2<300000){
      retorno = 400;
      numeroTres();
    }else if(R2<400000){
      retorno = 200;
      numeroCuatro();
    }else{
      retorno = 100;
      numeroCinco();
    }
    //delay(500);
  }
  return retorno;
}
/**************************************************************/
