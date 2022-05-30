#include <iostream>

void Particao(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j)/2];

    do
    {
        while (x > A[*i])
        {
            (*i)++;
        }
        while (x < A[*j])
        {
            (*j)--;
        }
        if (*i <= *j)
        {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
        }
        
        
        
    } while (*i <= *j);
    

}

void Ordena(int Esq, int Dir, int *A){
    int i,j = 0;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j)
    {
        Ordena(Esq, j, A);
    }
    if (i < Dir)
    {
        Ordena(i, Dir, A);
    }
    
}

void QuickSort(int *A, int n)
{
    Ordena(0, n-1, A);
}

int main(){

    int vetor[9] = {0,15,12,1,5,7,23,56,22};
    
    for (int i = 0; i < 9; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
   
    QuickSort(vetor, 8);

    for (int i = 0; i < 9; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}