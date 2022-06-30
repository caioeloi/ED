#include <iostream>
#include <string>
using namespace std;
#define Troca(A, B) {Pais c = A; A = B; B = c; }




class Pais
{

public:
    string nome;
    int ouro = 0;
    int prata = 0;
    int bronze = 0;
    friend bool operator < (Pais& c1, Pais& c2);
    friend bool operator > (Pais& c1, Pais& c2);
    friend bool operator == (const Pais &lhs, const Pais &rhs);
    
};

bool operator < (Pais& c1, Pais& c2){
    if (c1.ouro < c2.ouro)
    {
        return true;
    }
    else if (c1.ouro > c2.ouro)
    {
        return false;
    }
    else if (c1.ouro == c2.ouro)
    {
        if (c1.prata < c2.prata)
        {
            return true;
        }
        else if (c1.prata > c2.prata)
        {
            return false;
        }
        else if (c1.prata == c2.prata)
        {
            if (c1.bronze < c2.bronze)
            {
                return true;
            }
            else if (c1.bronze > c2.bronze)
            {
                return false;
            }
            else if (c1.bronze == c2.bronze)
            {
                if (c1.nome > c2.nome)
                {
                    return true;
                }else{return false;}
                
            }
            
        }   
    }
    return false;
}

bool operator > (Pais& c1, Pais& c2){
    if (c1.ouro > c2.ouro)
    {
        return true;
    }
    else if (c1.ouro < c2.ouro)
    {
        return false;
    }
    else if (c1.ouro == c2.ouro)
    {
        if (c1.prata > c2.prata)
        {
            return true;
        }
        else if (c1.prata < c2.prata)
        {
            return false;
        }
        else if (c1.prata == c2.prata)
        {
            if (c1.bronze > c2.bronze)
            {
                return true;
            }
            else if (c1.bronze < c2.bronze)
            {
                return false;
            }
            else if (c1.bronze == c2.bronze)
            {
                if (c1.nome < c2.nome)
                {
                    return true;
                }else{
                    return false;
                }
                
            }
            
        }   
    }
    return false;

}

void Selecao (Pais *v, int n)
{
    int i, j, Max;
    for (i = 0; i < n - 1; i++){
        Max = i;
        for (j = i + 1 ; j < n; j++){
            if (v[j] > v[Max])
                Max = j;
        }
        Troca(v[i], v[Max]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Pais quadro[n];
    Pais aux;
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        cin >> aux.nome >> aux.ouro >> aux.prata >> aux.bronze;
        quadro[i] = aux;
    }

    
    Selecao(quadro, n);

    for ( i = 0; i < n - 1; i++)
    {
        cout << quadro[i].nome << " " << quadro[i].ouro << " " << quadro[i].prata << " " << quadro[i].bronze << endl;
    }

    cout << quadro[i].nome << " " << quadro[i].ouro << " " << quadro[i].prata << " " << quadro[i].bronze;

    
    return 0;
}

