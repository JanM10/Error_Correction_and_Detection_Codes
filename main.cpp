#include <iostream>
#include "Paridad.h"
#include "Redundancia_ciclica.h"
#include <string>
using namespace std;

Paridad par;
Redundancia_ciclica red;

int main() {
/* Driver program to test getParity() */
    //Paridad par
    unsigned int n = 7;
    cout<<"Numero de paridad "<< n <<" = "<<(par.getParidad(n)? "impar": "par");

    //Redundancia ciclica
    string dato = "11011001";
    string llave = "00101";
    red.codificarDatos(dato, llave);

    return 0;
}
