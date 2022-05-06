#ifndef MATH
#define MATH

#include <string>
using namespace std;

class mat_tipo {

  public:
    mat_tipo(const int &tx, const int &ty);
    void inicializaMatrizNula();
    void imprimeMatriz() const;
    mat_tipo transpoeMatriz() const;
    double acessaMatriz() const;
    ~mat_tipo();
    double getElement(const int &x, const int &y) const;
    double *getAddress(const int &x, const int &y) const;
    void setElement(const int &x, const int &y, const double &v);
    mat_tipo operator+(const mat_tipo &mat);
    mat_tipo operator*(const mat_tipo &mat);

  private:
    double **m;
    int tamx, tamy;
    int id;
};

#endif
