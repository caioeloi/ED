#include <iostream>
#include "Lista.h"

int main(int argc, char const *argv[])
{
    Lista cartas;
    cartas.InsereInicio('a');
    cartas.InsereFinal('b');
    cartas.InsereFinal('c');
    cartas.InsereFinal('d');
    cartas.Imprime();   
    cartas.RemovePosicao(2);
    cartas.Imprime();
    return 0;
}
