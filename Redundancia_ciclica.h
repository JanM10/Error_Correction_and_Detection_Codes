#ifndef ERROR_CORRECTION_AND_DETECTION_CODES_REDUNDANCIA_CICLICA_H
#define ERROR_CORRECTION_AND_DETECTION_CODES_REDUNDANCIA_CICLICA_H

#include <string>
#include <iostream>
using namespace std;

class Redundancia_ciclica {
public:
    string xor1(string a, string b);
    string mod2div(string dividendo, string divisor);
    void codificarDatos(string dato, string llave);
};


#endif //ERROR_CORRECTION_AND_DETECTION_CODES_REDUNDANCIA_CICLICA_H



