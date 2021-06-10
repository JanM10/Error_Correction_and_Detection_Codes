#include <iostream>
#include "Paridad.h"
using namespace std;

Paridad par;

int main() {
/* Driver program to test getParity() */

    unsigned int n = 7;
    cout<<"Parity of no "<<n<<" = "<<(par.getParity(n)? "odd": "even");
    
    return 0;
}
