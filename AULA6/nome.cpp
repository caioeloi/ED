#include <iostream>
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

void Frequencia(int *v, int n){
int aux = 0;
int contador = 1;

for (int i = 0; i <= n; i++){
contador = 1;
aux = v[i];

if (aux != v[i -1] || i == 0){
for (int j = i+1; j <= n; j++){
if (v[j] == aux){
contador++;
}else{
cout << aux << " aparece " << contador << " vez(es)" << endl;
break;
}

}
}
}
}

int main()
{
    int n;

    cin>>n;

    int vet[n];

    for(int i=0;i cin>>vet[i];
    }

    Selecao(vet,n);

    Frequencia(vet,n);


    return 0;
}

