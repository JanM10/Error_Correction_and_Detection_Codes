#include "Paridad.h"

// Function to get parity of number n. It returns 1
// if n has odd parity, and returns 0 if n has even
// parity
bool Paridad::getParidad(unsigned int n)
{
    bool paridad = 0;
    while (n)
    {
        paridad = !paridad;
        n	 = n & (n - 1);
    }
    return paridad;
}

