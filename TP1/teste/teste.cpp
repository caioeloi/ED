#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ofstream fout("teste1.txt");
    string saida = "Ola";
    saida += "\ntudo bem?";
    int saldo = 123;
    saida += to_string(saldo);
    fout << saida;


}
