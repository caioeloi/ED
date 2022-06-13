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
        int tam = 0;
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
    string RemovePosicao(int pos);
    Lista ordenaPalavras(Lista palavras);


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

string Lista::RemovePosicao(int pos) {;
    string aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == NULL)
        ultimo = p;
    return aux;
}



Lista Lista::ordenaPalavras(Lista palavras){
    Lista aux;
    Lista aux2 = palavras;

    string menor;
    string auxiliar;
    int cont = 0;
    int index = 0;
    int i = 0;

    do
    {
        index = 0;
        for (i = 0; i < aux2.tamanho; i++)
        {
            auxiliar = aux2.GetItem(i+1);
            if (auxiliar.length() < menor.length())
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


    palavras = aux;

    return palavras;

   


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
    nova->tam = item.length();
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
    nova->tam = item.length();
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
    ifstream arq;
    arq.open("entrada.txt");
    
    int n = 0;
    int i = 0;
    string aux;
    getline(arq, aux);
    n = stoi(aux);

    Lista frase;
    string palavrinha;
    int j = 0;
    size_t pos = 0;
    string space_delimiter = " ";
    for ( i = 0; i < n; i++)
    {
        j = 0;
        getline(arq, aux);
        while ((pos = aux.find(space_delimiter)) != string::npos) {    
            palavrinha = aux.substr(0, pos);
            aux.erase(0, pos + space_delimiter.length());




            
            if (j == 0)
            {
                frase.InsereInicio(palavrinha);
            }else{
                frase.InsereFinal(palavrinha);
            }
            j++; 
            
        }
        for ( j = 0; j < frase.tamanho; j++)
        {
            cout << frase.GetItem(j+1) << endl;
        }
        break;
        
        //frase = frase.ordenaPalavras(frase);

        
        

        

    }
    

    
    

    
    
    
    return 0;
}
