#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string frase;
    string palavra;
    string palavra2;
    int numFrases;
    cin >> numFrases;
    cin.ignore();
    int i,j,k = 0;
    int contador = 1;
    int posicao = 0;
    int count = 0;
    string palavras[128];
    

    for ( k = 0; k < numFrases; k++){
        j = 0;
        count = 0;
        palavras->erase();
        contador = 1;
        getline(cin, frase);
        for ( i = 0; i < frase.length(); i++)
        {
            if (isspace(frase[i]))
            {
                contador++;
            }
        }

        for ( i = 0; i <= frase.length(); i++)
        {
            if (isspace(frase[i]) || frase[i] == '\0')
            {
                palavras[j] = palavra;
                palavra.erase();
                j++;
            }else{
                palavra += frase[i];
            }
        }
        cin >> palavra2;
        cin.ignore();

        posicao = 0;
        for ( i = 0; i < contador; i++)
        {
            if (palavras[i] == palavra2)
            {
                if (count == 0)
                {
                    cout << posicao;
                    count++;
                }else{
                    cout << " " << posicao;
                }
                
                
                
                
            }
            posicao += palavras[i].length() + 1;
            
        }
        if (count == 0)
        {
            cout << -1;
        }
        
        cout << endl;
        

    }

    

    

    
    
    
    
    
    
    



    return 0;
}
