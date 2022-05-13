class TipoNo
{
    public:
        TipoNo(int valor);
    private:
        int item;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};

class ArvoreBinaria
{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(int item);
        void Caminha(int tipo);
        void Limpa();
    private:
        void InsereRecursivo(TipoNo* &p, int item);
        void ApagaRecursivo(int* p);
        void PorNivel();
        void PreOrdem(int* p);
        void InOrdem(int* p);
        void PosOrdem(int* p);
        TipoNo *raiz;
};

TipoNo::TipoNo(int item)
{
    this->item = item;
    esq = nullptr;
    dir = nullptr;
}


ArvoreBinaria::ArvoreBinaria()
{
    this->raiz = nullptr;
}


ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}

void ArvoreBinaria::Insere(int item){
    InsereRecursivo(this->raiz,item);
}
void ArvoreBinaria::InsereRecursivo(TipoNo* &p, int item){
    if(p==nullptr){
        p = new TipoNo(item);
        p->item = item;
    }
    else if(item < p->item){
        InsereRecursivo(p->esq, item);
    }
    else{
        InsereRecursivo(p->dir, item);
    }
}

