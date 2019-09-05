#include "Matriz.h"
#include "iostream"

using namespace std;

// Todos los valores a 0.
Matriz::Matriz(): matriz{nullptr}, filas {0}, columnas{0} {

}

// Crear matriz
Matriz::Matriz(int f, int c): filas {f}, columnas{c} {

    matriz = new int*[filas];
    for (int i= 0 ; i < filas; i++){
        matriz[i] = new int[columnas];
    }
}

// Destructor
Matriz::~Matriz() {
    //delete [] matriz;
}

// Llenar matriz
void Matriz::llenar(){

    int mult = filas*columnas;
    if(mult%2==0) { //par
        for (int k = 0; k < (mult/ 2) + 1; k++) {
            int m = (rand() % 8) + 1;
            long f,c;
            f = random()%(filas);
            c = random()%(columnas);
            if( matriz[f][c] == 0)
                matriz[f][c] = m;
            else
                k--;
        }
    }
    else { //impar
        for (int k = 0; k < ((mult-1)/ 2) + 1; k++) {
            long f,c;
            int m = (rand() % 8) + 1;
            f = random()%(filas);
            c = random()%(columnas);
            if( matriz[f][c] == 0)
                matriz[f][c] = m;
            else
                k--;
        }
    }
}


// Imprimir matriz
void Matriz::imprimir(){

  for ( int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cout<<matriz[i][j]<<"  ";
    }
    cout << endl;
  }
}


// Producto Punto
void Matriz::escalar(const Matriz& M1, int num) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j] = temporal.matriz[i][j] * num;
        }
    }
}


// Trasposición de matriz
void Matriz::transposicion(const Matriz& M1) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j]=temporal.matriz[j][i];
        }
    }
}

// Sobrecarga de operador + (suma)
Matriz Matriz::operator+(const Matriz& M1){

    Matriz temporal(M1);
      for(int i = 0; i < M1.filas; i++){
        for (int j = 0; j < M1.columnas; j++) {
          temporal.matriz[i][j] += this->matriz[i][j];
        }
      }
      return temporal;
}

// Sobrecarga operador * (multiplicacion)
Matriz Matriz::operator*(const Matriz& M1){

    Matriz temporal(M1);
    for(int i = 0; i < M1.filas; i++){
        for(int j = 0; j < M1.columnas; ++j){
            for(int z=0; z < this->columnas; ++z){
                temporal.matriz[i][j] += this->matriz[i][z] * this->matriz[z][j];
              }
            }
          }
    return temporal;
}

// Sobrecarga operador =
Matriz Matriz::operator=(const Matriz & M1) {

    if(this->filas !=0 && this->columnas!=0){
        delete [] this->matriz;
    }

    this->filas = M1.filas;
    this->columnas = M1.columnas;

    this->matriz = new int*[this->filas];

    for (int i = 0; i < this->filas; ++i) {
        this->matriz[i] = new int[this->columnas];
        for (int j = 0; j < this->columnas; ++j) {
            this->matriz[i][j] = M1.matriz[i][j];
        }
    }
    return *this;
}




