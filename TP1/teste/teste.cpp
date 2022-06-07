#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream arq;
    arq.open("teste.txt");
    string nome;
    string contarq;
    arq >> nome;

    arq >> contarq;
    if (!isdigit(contarq[0]))
    {
        nome += " " + contarq;
    }
    
  
    cout << nome << endl;
    arq.close();



}
