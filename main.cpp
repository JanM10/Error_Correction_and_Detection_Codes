#include <iostream>
#include <string>
#include <vector>

#include "Paridad.h"
#include "Redundancia_ciclica.h"
#include "Hamming.h"
using namespace std;

Paridad par;
Redundancia_ciclica red;
Hamming ham;

int main() {
    //Paridad par
    unsigned int n = 7;
    cout<<"Numero de paridad "<< n <<" = "<<(par.getParidad(n)? "impar": "par") << endl;
    cout << endl;


    //Redundancia ciclica
    string dato = "11011001";
    string llave = "00101";
    red.codificarDatos(dato, llave);


    //Código de Hamming
    vector<int> msgBit = { 0, 0, 0, 1 , 1, 0, 0, 1, 0, 1}; //Bits de mensaje dados
    cout << endl;
    ham.encontrarCodigoHamming(msgBit);

    return 0;
}
