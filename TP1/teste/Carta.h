#ifndef CARTA_H
#define CARTA_H

#include <iostream>
using namespace std;


class Carta
{
private:
    /* data */
public:
    Carta(){};
    int numero;
    char naipe;
    //~Carta();
    void Imprime();

    friend bool operator < (Carta& c1, Carta& c2);
    friend bool operator > (Carta& c1, Carta& c2);
    
};

bool operator == (const Carta &lhs, const Carta &rhs);


#endif
