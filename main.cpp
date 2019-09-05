#include <iostream>
#include "Matriz.cpp"

using namespace std;

int main() {
    srand(time(nullptr));
    cout<< "OPERACIONES CON MATRICES CUADRADAS"<<endl;
    int filas, columnas;
    cout<<"Ingresa las filas: ";
    cin>>filas;
    cout<<"Ingresa las columnas: ";
    cin >> columnas;


    if (filas == columnas) {

        auto M1=new Matriz(filas,columnas);
        auto M2=new Matriz(filas,columnas);
        auto Msuma=new Matriz(filas,columnas);
        auto Mtrans=new Matriz(filas,columnas);
        auto ME = new Matriz(filas,columnas);

        M1->llenar();
        cout << "Matriz 1: " << '\n';
        M1->imprimir();
        cout << endl;


        M2->llenar();
        cout << "Matriz 2:" << '\n';
        M2->imprimir();
        cout << endl;

        *Msuma = *M1 + *M2;//Sobrecarga operador +

        cout << "La suma de M1 y M2 es: " << '\n';
        Msuma->imprimir();
        cout << endl;


        ME->escalar(*M1, 5);

        cout << "La mult escalar M1 es: " << '\n';
        ME->imprimir();


        Mtrans->transposicion(*M1);

        cout << "La transpuesta de M1 es: " << '\n';
        Mtrans->imprimir();
        cout << endl;


        auto Mx = new Matriz(filas, columnas);
        auto My = new Matriz(filas, columnas);


        Mx->llenar();

        cout << "Matriz x: " << '\n';
        Mx->imprimir();
        cout << endl;

        My->llenar();
        cout << "Matriz y:" << '\n';
        My->imprimir();

        cout << endl;


        auto M_mult = new Matriz(filas, columnas);

        *M_mult = *Mx * *My; //Sobrecarga operador *

        cout << "La multiplicacion de Mx y My es: " << '\n';
        M_mult->imprimir();
        cout << endl;


        delete M1;
        delete M2;
        delete Msuma;
        delete Mtrans;
        delete ME;
        delete Mx;
        delete My;
        delete M_mult;
    }

    else {
        cout << "ERROR: No es una matriz cuadrada";
    }
    return 0;

}

