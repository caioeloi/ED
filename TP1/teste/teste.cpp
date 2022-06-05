#include <iostream>
#include <regex>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "Lista.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Carta aux;
    aux.naipe = 'D';
    aux.numero = 12;
    Lista teste;
    teste.InsereInicio(aux);
    aux.naipe = 'F';
    aux.numero = 11;
    teste.InsereFinal(aux);

    teste.Imprime();

    teste.Limpa();

    aux.naipe = 'D';
    aux.numero = 12;

    teste.InsereInicio(aux);
    aux.naipe = 'F';
    aux.numero = 11;
    teste.InsereFinal(aux);
    teste.Imprime();


}
