#ifndef ERROR_CORRECTION_AND_DETECTION_CODES_HAMMING_H
#define ERROR_CORRECTION_AND_DETECTION_CODES_HAMMING_H
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Hamming {
public:
    vector<int> generarCodigoHamming(vector<int> msgBits, int m, int r);

    void encontrarCodigoHamming(vector<int>& msgBit);
};

#endif //ERROR_CORRECTION_AND_DETECTION_CODES_HAMMING_H

