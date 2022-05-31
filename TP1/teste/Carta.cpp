#include "Carta.h"


void Carta::Imprime(){
    std::cout << this->numero << " " << this->naipe;
}

bool operator == (const Carta &lhs, const Carta &rhs) {
    if (lhs.naipe == rhs.naipe && lhs.numero == lhs.numero)
    {
        return true;
    }else{
        return false;
    }
    
}

bool operator < (Carta& c1, Carta& c2){

    if (c1.numero < c2.numero)
    {
        return true;
    }else{
        return false;
    }
    

}

bool operator > (Carta& c1, Carta& c2){

    if (c1.numero > c2.numero)
    {
        return true;
    }else{
        return false;
    }
    
}

