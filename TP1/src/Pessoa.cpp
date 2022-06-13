#include "Pessoa.h"



int Pessoa::getSaldo() const{
    return this->saldo;
}

void Pessoa::setSaldo(const int saldo){
    this->saldo = saldo;
}

void Pessoa::ordenaCartas(){
    Lista aux;
    Lista aux2 = this->cartas;

    Carta menor;
    menor.numero = 14;
    Carta auxiliar;
    int cont = 0;
    int index = 0;
    int i = 0;

    do
    {
        menor.numero = 14;
        index = 0;
        for (i = 0; i < aux2.tamanho; i++)
        {
            auxiliar = aux2.GetItem(i+1);
            if (auxiliar < menor)
            {
                menor = auxiliar;
                index = i+1;
            }
        }
        if (cont == 0)
        {
            aux.InsereInicio(menor);
            cont++;

        }else{
            aux.InsereFinal(menor);
        }

        aux2.RemovePosicao(index);
        
        
    } while (aux2.tamanho > 0);


    this->cartas = aux;

   


}


/////////////////////////////////////////////JOGADAS/////////////////////////////////////////////

bool Pessoa::RoyalStraightFlush(){
    if (this->cartas.GetItem(1).numero == 1 && this->cartas.GetItem(2).numero == 10 && this->cartas.GetItem(3).numero == 11 && this->cartas.GetItem(4).numero == 12 && this->cartas.GetItem(5).numero == 13 && this->cartas.GetItem(1).naipe == this->cartas.GetItem(2).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(3).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(4).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(5).naipe)
    {
        return true;
    }else{
        return false;
    }
    
}

bool Pessoa::StraightFlush(){
    int match = 0;
    int aux = this->cartas.GetItem(1).numero;
    char aux2 = this->cartas.GetItem(1).naipe;
    if (this->cartas.GetItem(2).numero == aux + 1 && this->cartas.GetItem(3).numero == aux + 2 && this->cartas.GetItem(4).numero == aux + 3 && this->cartas.GetItem(5).numero == aux + 4 && aux2 == this->cartas.GetItem(2).naipe && aux2 == this->cartas.GetItem(3).naipe && aux2 == this->cartas.GetItem(4).naipe && aux2 == this->cartas.GetItem(5).naipe)
    {
        return true;
    }
    return false;
}

bool Pessoa::FourOfAKind(){
    int match = 0;
    int aux = 0;
    for (int i = 1; i <= this->cartas.tamanho; i++)
    {
        match = 0;
        aux = this->cartas.GetItem(i).numero;
        for (int j = i+1; j <= this->cartas.tamanho; j++)
        {
            if (aux == this->cartas.GetItem(j).numero)
            {
                match++;
            }else{
                break;
            }
        }
        if (match == 3)
        {
            return true;
        }
        

    }
    return false;
}

bool Pessoa::FullHouse(){
    if (this->ThreeOfAKind() && this->OnePair())
    {
        return true;
    }
    return false;

}

bool Pessoa::Flush(){
    if (this->cartas.GetItem(1).naipe == this->cartas.GetItem(2).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(3).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(4).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(5).naipe)
    {
        return true;
    }
    
    return false;

}

bool Pessoa::Straight(){

    if (this->cartas.GetItem(2).numero == this->cartas.GetItem(1).numero + 1 && this->cartas.GetItem(3).numero == this->cartas.GetItem(1).numero + 2 && this->cartas.GetItem(4).numero == this->cartas.GetItem(1).numero + 3 && this->cartas.GetItem(5).numero == this->cartas.GetItem(1).numero + 4 )
    {
        return true;
    }
    
    return false;
}

bool Pessoa::ThreeOfAKind(){
    int contador = 0;
    int aux = 0;
    for (int i = 1; i < this->cartas.tamanho; i++)
    {
        contador = 0;
        aux = this->cartas.GetItem(i).numero;
        for (int j = i+1; j <= this->cartas.tamanho; j++)
        {
            if (aux == this->cartas.GetItem(j).numero)
            {
                contador++;
            }
        }
        if (contador == 2) return true;
    }
    return false;
}

bool Pessoa::TwoPairs(){
    int iguais = 0;
    int diferentes = 0;
    int aux = 0;
    int pair = 0;
    for (int i = 1; i < this->cartas.tamanho; i++)
    {
        iguais = 0;
        diferentes = 0;
        aux = this->cartas.GetItem(i).numero;
        for (int j = i+1; j <= this->cartas.tamanho; j++)
        {
            if (aux == this->cartas.GetItem(j).numero)
            {
                iguais++;
            }else{
                diferentes++;
            }
        }
        if (iguais == 1 && diferentes == this->cartas.tamanho - (i+1))
        {
            pair++;
        }
        
    }
    if (pair == 2)
    {
        return true;
    }
    
    return false;

}

bool Pessoa::OnePair(){
    int iguais = 0;
    int diferentes = 0;
    int aux = 0;
    for (int i = 1; i < this->cartas.tamanho; i++)
    {
        iguais = 0;
        diferentes = 0;
        aux = this->cartas.GetItem(i).numero;
        for (int j = i+1; j <= this->cartas.tamanho; j++)
        {
            if (aux == this->cartas.GetItem(j).numero)
            {
                iguais++;
            }else{
                diferentes++;
            }
        }
        if(i > 1){
            if (iguais == 1 && diferentes == this->cartas.tamanho - (i+1) && aux != this->cartas.GetItem(i-1).numero)
            {
                return true;
            }
        }else{
            if (iguais == 1 && diferentes == this->cartas.tamanho - (i+1))
            {
                return true;
            }
        }
        
        
        
    }
    return false;
}




////////////////////////////////////////////////////////////////////////////////////////////////


void Pessoa::setJogada(){
    if (this->cartas.tamanho == 0)
    {
        this->valorjogada = 0;
        this->jogada = "none";
    }
    
    else if (this->RoyalStraightFlush())
    {
        this->valorjogada = 10;
        this->jogada = "RSF";
    }
    else if(this->StraightFlush()){
        this->valorjogada = 9;
        this->jogada = "SF";
    }
    else if(this->FourOfAKind()){
        this->valorjogada = 8;
        this->jogada = "FK";
    }
    else if(this->FullHouse()){
        this->valorjogada = 7;
        this->jogada = "FH";
    }
    else if(this->Flush()){
        this->valorjogada = 6;
        this->jogada = "F";
    }
    else if(this->Straight()){
        this->valorjogada = 5;
        this->jogada = "S";
    }
    else if(this->ThreeOfAKind()){
        this->valorjogada = 4;
        this->jogada = "TK";
    }
    else if(this->TwoPairs()){
        this->valorjogada = 3;
        this->jogada = "TP";
    }
    else if(this->OnePair()){
        this->valorjogada = 2;
        this->jogada = "OP";
    }else{
        this->valorjogada = 1;
        this->jogada = "HC";
    }
}

int Pessoa::getValorJogada(){

    return this->valorjogada;
}

string Pessoa::getJogada(){


    return this->jogada;
}

