#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta
{
private:
    /* data */
public:
    Carta(const string& naipe, const int numero);
    int numero;
    string naipe;
    //~Carta();
};




#endif
