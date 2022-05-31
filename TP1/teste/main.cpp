#include <iostream>
#include "Pessoa.h"

int main(int argc, char const *argv[])
{
    Lista cartas;
    Carta ajuda;

    Pessoa pessoa1("Caio Eloi", 1000);

    ajuda.naipe = 'O';
    ajuda.numero = 6;
    cartas.InsereInicio(ajuda);

    ajuda.naipe = 'P';
    ajuda.numero = 3;
    cartas.InsereFinal(ajuda);

    ajuda.naipe = 'E';
    ajuda.numero = 10;
    cartas.InsereFinal(ajuda);

    ajuda.naipe = 'O';
    ajuda.numero = 11;
    cartas.InsereFinal(ajuda);

    ajuda.naipe = 'O';
    ajuda.numero = 1;
    cartas.InsereFinal(ajuda);
   
    Carta c1;
    pessoa1.cartas = cartas;

    pessoa1.cartas.Imprime();

    pessoa1.ordenaCartas();

    pessoa1.cartas.Imprime();



    return 0;
}
