#include <iostream>
#include <regex>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string nomeArq = "entrada.txt";
    ifstream arq;
    arq.open(nomeArq);

    int jogadas = 0;
    int saldo = 0;
    int pingo = 0;
    int saldoJog = 0;
    int numJogadores = 0;

    arq >> jogadas >> saldo;

    arq >> numJogadores >> pingo;

    string nome, aux1, aux2, aux3, aux4, aux5;

    arq >> nome >> saldoJog >> aux1 >> aux2 >> aux3 >> aux4 >> aux5;

    int i = 0;
    int j = 0;
    cout << aux3.length() << endl;

    if (aux3.length() == 3)
    {
        j = stoi(aux3.substr(0,2));
    }
    
    cout << j << endl;






    



    arq.close();
    return 0;
}
