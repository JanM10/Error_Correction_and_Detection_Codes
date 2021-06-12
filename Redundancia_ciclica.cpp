#include "Redundancia_ciclica.h"

//Devuelve el XOR de 'a' y 'b' (ambos de la misma longitud)
string Redundancia_ciclica::xor1(string a, string b)
{
    string resultado = "";

    int n = b.length();

    //Recorrer todos los bits, si los bits son iguales, entonces XOR es 0, si no 1
    for(int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            resultado += "0";
        else
            resultado += "1";
    }
    return resultado;
}

//Realiza la división Modulo-2
string Redundancia_ciclica::mod2div(string dividendo, string divisor)
{
    // Numero de bits al que se les aplica XOR a la vez
    int seleccion = divisor.length();

    //Cortar el dividendo a la longitud adecuada para cada paso
    string tmp = dividendo.substr(0, seleccion);

    int n = dividendo.length();

    while (seleccion < n)
    {
        if (tmp[0] == '1')

            //Reemplazar el dividendo por el resultado de XOR y tirar 1 bit hacia abajo
            tmp = xor1(divisor, tmp) + dividendo[seleccion];
        else

            //Si el bit más a la izquierda es '0'.
            //Si el bit más a la izquierda del dividendo (o la
            //parte utilizada en cada paso) es 0, el paso no puede
            //utilizar el divisor normal; tenemos que utilizar un
            //divisor todo-0.
            tmp = xor1(std::string(seleccion, '0'), tmp) + dividendo[seleccion];

        //Incrementar la selección para avanzar
        seleccion += 1;
    }

//Para los últimos n bits, tenemos que llevarlo a cabo normalmente ya que el aumento del valor del pick provocará Índice fuera de límites.
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(seleccion, '0'), tmp);

    return tmp;
}

//Función utilizada en el lado del emisor para codificar los datos añadiendo el resto de la división modular al final de los datos.
void Redundancia_ciclica::codificarDatos(string dato, string llave)
{
    int tamanoLLave = llave.length();

    // Agrega n-1 ceros al final del dato
    string appended_data = (dato +string(tamanoLLave - 1, '0'));

    string remainder = mod2div(appended_data, llave);

    // Agrega lo que sobrea al dato original
    string datoNuevo = dato + remainder;
    cout << "Sobrante : "<< remainder << "\n";
    cout << "Dato + Sobrante :"<< datoNuevo << "\n";
}