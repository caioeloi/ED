#include <iostream>
#include <string>
 
using namespace std;



class TipoCelula
{
    public:
        TipoCelula(char valor);
    private:
        char item;
        TipoCelula *prox;
    
    friend class PilhaEncadeada;
};

class PilhaEncadeada
{
    public:
        PilhaEncadeada();
        void Empilha(char item);
        char Desempilha();
        int tamanho;
    private:
        TipoCelula* topo;
};


TipoCelula::TipoCelula(char valor){
    this->item = valor;
    prox = nullptr;
}

PilhaEncadeada::PilhaEncadeada()
{
    topo = nullptr;
    tamanho = 0;
}

void PilhaEncadeada::Empilha(char item){
    TipoCelula *nova;
    nova = new TipoCelula(item);
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

char PilhaEncadeada::Desempilha(){
    char aux; TipoCelula *p;
    if(tamanho == 0)
        throw "A pilha está vazia!";
    
    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;
    return aux;
};


int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    PilhaEncadeada grande;
    
    for (auto i : S)
    {
        if (i == '(')
        {
            grande.Empilha(i);
        }
        else if(i == ')' && grande.tamanho > 0){
            grande.Desempilha();
        }
       
    }

    if(grande.tamanho > 0){
        cout << "Ainda temos " << grande.tamanho <<" assunto(s) pendente(s)!" <<  endl;
    }else{
        cout << "Partiu RU!" << endl;
    }


    return 0;
}
