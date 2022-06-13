#ifndef CARTA_H
#define CARTA_H

#include <iostream>
using namespace std;


class Carta
{

public:
    Carta(){};
    int numero;
    char naipe;
    friend bool operator < (Carta& c1, Carta& c2);
    friend bool operator > (Carta& c1, Carta& c2);
    
};

bool operator == (const Carta &lhs, const Carta &rhs);

#endif
