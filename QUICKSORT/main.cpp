#include <iostream>
#include "Carta.h"
using namespace std;
#define Troca(A, B) {int c = A; A = B; B = c; }

void Selecao (int *v, int n)
{
    int i, j, Min;
    for (i = 0; i < n - 1; i++){
        Min = i;
        for (j = i + 1 ; j < n; j++){
            if (v[j] < v[Min])
            Min = j;
        }
        Troca(v[i], v[Min]);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
