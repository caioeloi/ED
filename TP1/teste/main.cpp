#include <iostream>
#include "Pessoa.h"

int main(int argc, char const *argv[])
{
    Lista cartas;
    Carta ajuda;

    Pessoa pessoa1("Caio Eloi", 1000);

    ajuda.naipe = 'O';
    ajuda.numero = 1;
    cartas.InsereInicio(ajuda);

    ajuda.naipe = 'O';
    ajuda.numero = 2;
    cartas.InsereFinal(ajuda);

    ajuda.naipe = 'O';
    ajuda.numero = 3;
    cartas.InsereFinal(ajuda);

    ajuda.naipe = 'O';
    ajuda.numero = 4;
    cartas.InsereFinal(ajuda);

    ajuda.naipe = 'O';
    ajuda.numero = 5;
    cartas.InsereFinal(ajuda);
   
    pessoa1.cartas = cartas;

    pessoa1.ordenaCartas();

    pessoa1.cartas.Imprime();

    pessoa1.getJogada();




    return 0;
}
