#include <iostream>

using namespace std;

class TipoCelula
{
    public:
        TipoCelula();
    private:
        int item;
        TipoCelula *prox;
        friend class ListaEncadeada;
};

TipoCelula::TipoCelula()
{
    item = -1;
    prox = nullptr;
}

class ListaEncadeada {
    public:
        ListaEncadeada();
        int GetItem(int pos);
        void SetItem(int item, int pos);
        void InsereFinal(int item);
        int Pesquisa(int c);
        int tamanho = 0;
    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
};

ListaEncadeada::ListaEncadeada() {
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
        p = p->prox;
    return p;
}


int ListaEncadeada::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
}

int ListaEncadeada::Pesquisa(int c) {
    int aux = -1; // construtor seta o item para -1;
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=nullptr) {
        if (p->item == c) {
        aux = p->item;
        break;
        }
        p = p->prox;
    }
    return aux;
};

void ListaEncadeada::InsereFinal(int item) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = nullptr;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};





class Hash_LE
{
    public:
        Hash_LE(){};
        int Pesquisa(int chave, int mod);
        void Insere(int item, int mod);
        static const int M = 100;
        int Hash(int Chave, int mod);
        ListaEncadeada Tabela[M];
        
};


int Hash_LE::Hash(int Chave, int mod){

    int aux;
    aux = Chave % mod;
    return aux;
}

int Hash_LE::Pesquisa(int chave, int mod){
    int pos;
    int item;
    pos = Hash(chave, mod);
    item = Tabela[pos].Pesquisa(chave);
    return item;
}



void Hash_LE::Insere(int item, int mod){
    int aux = -1;
    int pos;
    aux = Pesquisa(item, mod);
    if(!aux == -1)
        throw("Erro: Item já está presente");
    pos = Hash(item, mod);
    Tabela[pos].InsereFinal(item);
}



void imprimelista(ListaEncadeada lista){
    int i = 0;
    for (i = 0; i < lista.tamanho; i++)
    {
        if (i == lista.tamanho - 1)
        {
            cout << lista.GetItem(i+1) << " -> \\";
        }else{
            cout << lista.GetItem(i+1) << " -> ";
        }
        
    }
    
}

void imprimehash(Hash_LE tabhashm, int tam){
    for (int i = 0; i < tam; i++)
    {
        cout << i << " -> ";
        if (tabhashm.Tabela[i].tamanho == 0)
        {
            cout << "\\";
        }
        
        imprimelista(tabhashm.Tabela[i]);
        cout << endl;
    }
    
    
}

int main(int argc, char const *argv[])
{
    int N, M, C = 0;
    cin >> N;
    int numero = 0;
    for (int i = 0; i < N; i++)
    {
        Hash_LE tabhash;
        cin >>  M >> C;
        for (int j = 0; j < C; j++)
        {
            cin >> numero;
            tabhash.Insere(numero, M);
        }
        imprimehash(tabhash, M);
        if (i != N-1)
        {
            cout << endl;
        }
        

    }

    
    return 0;
}