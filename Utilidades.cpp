#include "Utilidades.h"
#include <string>

using namespace std;

string Utilidades::formatearMoneda(double valor) {
    return "Q" + to_string(valor);
}

int Utilidades::factorial(int numero) {

    if (numero <= 1)
        return 1;

    return numero * factorial(numero - 1);
}