#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class TipoCelula
{
    public:
        TipoCelula(string valor);
    private:
        string item;
        TipoCelula *prox;
    
    friend class Lista;
};

TipoCelula::TipoCelula(string valor){
    this->item = "valor";
    this->prox = nullptr;
}

class Lista
{
public:
    Lista();
    int tamanho = 0;
    string GetItem(int pos);
    void InsereInicio(const string item);
    void InsereFinal(const string item);
    void Limpa();

private:
    TipoCelula* topo = nullptr;
    TipoCelula* ultimo = nullptr;
    TipoCelula* Posiciona(int pos, bool antes);
};

Lista::Lista()
{
    string aux;
    topo = new TipoCelula(aux);
    ultimo = topo;

}

TipoCelula* Lista::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = topo;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
    p = p->prox;
    return p;
}



void Lista::InsereInicio(const string item)
{
    TipoCelula *nova;
    nova = new TipoCelula(item);
    nova->item = item;
    nova->prox = topo->prox;
    topo->prox = nova;
    tamanho++;
    if(nova->prox == NULL)
        ultimo = nova;
}

void Lista::InsereFinal(const string item)
{
    TipoCelula *nova;
    nova = new TipoCelula(item);
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};

void Lista::Limpa() {
    TipoCelula *p;
    p = topo->prox;
    while (p!=nullptr) {
        topo->prox = p->prox;
        delete p;
        p = topo->prox;
    }
    ultimo = topo;
    tamanho = 0;
};

string Lista::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
}

int main(int argc, char const *argv[])
{
    Lista palavras;
    string aux = "ola";

    palavras.InsereInicio(aux);

    aux = "tudobom?";
    int i = 0;
    palavras.InsereFinal(aux);

    for ( i = 1; i <= palavras.tamanho; i++)
    {
        cout << palavras.GetItem(i) << endl;
    }


    
    
    return 0;
}
