#include "Pessoa.h"


Pessoa::Pessoa(const string& nome, const int saldo){
    this->nome = nome;
    this->saldo = saldo;
}

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

string Pessoa::getJogada(){

    int tamaux = this->cartas.tamanho;
    int vet[tamaux];
    Carta aux;

    if (this->cartas.GetItem(1).numero == 1 && this->cartas.GetItem(2).numero == 10 && this->cartas.GetItem(3).numero == 11 && this->cartas.GetItem(4).numero == 12 && this->cartas.GetItem(5).numero == 13 && this->cartas.GetItem(1).naipe == this->cartas.GetItem(2).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(3).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(4).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(5).naipe)
    {
        this->jogada = "RSF";
        return "RSF";
    }
    else if (this->cartas.GetItem(2).numero == this->cartas.GetItem(1).numero + 1 && this->cartas.GetItem(3).numero == this->cartas.GetItem(1).numero + 2 && this->cartas.GetItem(4).numero == this->cartas.GetItem(1).numero + 3 && this->cartas.GetItem(5).numero == this->cartas.GetItem(1).numero + 4 && this->cartas.GetItem(1).naipe == this->cartas.GetItem(2).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(3).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(4).naipe && this->cartas.GetItem(1).naipe == this->cartas.GetItem(5).naipe)
    {
        this->jogada = "SF";
        return "SF";
    }
    else if ()
    {
        return "FK";
    }
    else if (/* condition */)
    {
        return "FH";
    }
    else if (/* condition */)
    {
        return "F";
    }
    else if (/* condition */)
    {
        return "S";
    }
    else if (/* condition */)
    {
        return "TK";
    }
    else if (/* condition */)
    {
        return "TP";
    }
    else if (/* condition */)
    {
        return "OP";

    }else{
        return "HC";
    }
    
    

}

