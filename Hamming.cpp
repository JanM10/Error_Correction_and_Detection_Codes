#include "Hamming.h"

//Función para generar el código hamming
vector<int> Hamming::generarCodigoHamming(vector<int> msgBits, int m, int r)
{
    //Almacena el Código Hamming
    vector<int> codigoHamming(r + m);

    //Encontrar las posiciones de los bits redundantes
    for (int i = 0; i < r; ++i) {
        //Colocando -1 en los bits redundantes lugar para identificarlo después
        codigoHamming[pow(2, i) - 1] = -1;
    }

    int j = 0;

    //Iterar para actualizar el código
    for (int i = 0; i < (r + m); i++) {
        // Colocación de msgBits donde -1 está ausente, es decir, excepto los bits redundantes bits todas las posiciones son msgBits
        if (codigoHamming[i] != -1) {
            codigoHamming[i] = msgBits[j];
            j++;
        }
    }

    for (int i = 0; i < (r + m); i++) {
        //Si el bit actual no es redundante bit, entonces continúa
        if (codigoHamming[i] != -1)
            continue;

        int x = log2(i + 1);
        int conteo = 0;

        // Encontrar los bits de msg que contienen el bit set en la posición x
        for (int j = i + 2;
             j <= (r + m); ++j) {

            if (j & (1 << x)) {
                if (codigoHamming[j - 1] == 1) {
                    conteo++;
                }
            }
        }

        //Generación de código hamming para paridad par
        if (conteo % 2 == 0) {
            codigoHamming[i] = 0;
        }
        else {
            codigoHamming[i] = 1;
        }
    }
    return codigoHamming;
}

//Función para encontrar el código hamming del bit del mensaje dado msgBit
void Hamming::encontrarCodigoHamming(vector<int>& msgBit)
{
    //Tamaño de los bits del mensaje
    int m = msgBit.size();

    //r es el número de bits redundantes
    int r = 1;

    //Encontrar el número de bits redundantes
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }

    //Generar código
    vector<int> ans = generarCodigoHamming(msgBit, m, r);

    //Imprimie el código
    cout << "Los bits del mensaje son: ";
    for (int i = 0; i < msgBit.size(); i++){
        cout << msgBit[i] << " ";
    }

    cout << "\nEl codigo Hamming es: ";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

}