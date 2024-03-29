#include "mat.h"
#include "memlog.h"
#include <gtest/gtest.h>

// Variáveis e constantes globais para teste
const int SIZE = 2;
memlog ml;

TEST(mat_tipo, iniciaMatrizNula) {

    // Initicialize matriz
    mat_tipo x(SIZE, SIZE);
    x.inicializaMatrizNula();

    // Assert
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            EXPECT_EQ(0, x.getElement(i, j));
}

TEST(mat_tipo, somaMatrizes) {

    // Initicialize matrizes e soma
    mat_tipo x(SIZE, SIZE);
    x.inicializaMatrizNula();
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            x.setElement(i, j, i * (j + 1));
    mat_tipo y(SIZE, SIZE);
    y.inicializaMatrizNula();
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            y.setElement(i, j, j * (i + 1));
    const matrix w = x + y;

    // Define matriz esperada
    mat_tipo z(SIZE, SIZE);
    z.inicializaMatrizNula();
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            z.setElement(i, j, i * (j + 1) + j * (i + 1));

    // Assert
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            EXPECT_EQ(w.getElement(i, j), z.getElement(i, j));
}

TEST(mat_tipo, multiplicaMatrizes) {

    // Initicialize matrizes e multiplica
    double xElements[SIZE * SIZE] = {1, 2, 3, 4};
    mat_tipo x(SIZE, SIZE);
    x.inicializaMatrizNula();
    for (int i = 0, k = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j, ++k)
            x.setElement(i, j, xElements[k]);

    int yElements[SIZE * SIZE] = {5, 6, 7, 8};
    mat_tipo y(SIZE, SIZE);
    y.inicializaMatrizNula();
    for (int i = 0, k = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j, ++k)
            y.setElement(i, j, yElements[k]);

    const matrix w = x * y;

    // Define matriz esperada
    int zElements[SIZE * SIZE] = {19, 22, 43, 50};
    mat_tipo z(SIZE, SIZE);
    z.inicializaMatrizNula();
    for (int i = 0, k = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j, ++k)
            z.setElement(i, j, zElements[k]);

    // Assert
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            EXPECT_EQ(w.getElement(i, j), z.getElement(i, j));
}

TEST(mat_tipo, transpoeMatriz) {

    const double arr[SIZE][SIZE * SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

    // Initicialize matriz e a transpõe
    mat_tipo x(SIZE, SIZE * SIZE);
    x.inicializaMatrizNula();
    for (int i = 0, k = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE * SIZE; ++j, ++k)
            x.setElement(i, j, arr[i][j]);
    mat_tipo xTransp = x.transpoeMatriz();

    // Define matriz esperada
    mat_tipo expect(SIZE * SIZE, SIZE);
    expect.inicializaMatrizNula();
    for (int i = 0, k = 0; i < SIZE * SIZE; ++i)
        for (int j = 0; j < SIZE; ++j, ++k)
            expect.setElement(i, j, arr[j][i]);

    // Assert
    for (int i = 0; i < SIZE * SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            EXPECT_EQ(xTransp.getElement(i, j), expect.getElement(i, j));
}

// Descrição: programa principal para execução de testes
// Entrada: argc,argv
// Saida: resultado dos testes
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
