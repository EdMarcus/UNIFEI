/* 
 * File:   Matriz.h
 * Author: Édlon de Sá
 * e-mail: edlondesa@gmail.com
 *
 * Created on 18 de Abril de 2016, 16:15
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

class Matriz {
private: //atributos
    int linhas, colunas;
    int **matriz;
public:
    Matriz(int l, int c);//construtor
    virtual ~Matriz(); //destrutor
    void insere(); //insere dados na matriz
    void mostra(); //exibe o conteudo da matriz
    bool matriz_quadrada();//Retorna se a matriz é quadrada
    int soma_diagonal();//Retorna a soma da diagonal principal
    int maximo();//Retorna o maior valor da matriz
    bool Triangular_Superior();//Retorna se a matriz é triangular superior
    bool Triangular_Inferior();//Retorna se a matriz é triangular inferior
    
    /* Adicional: Verifica se duas matrizes são multiplicáveis */
    friend bool Multiplicavel(Matriz& m1, Matriz& m2);
    
    Matriz operator + (Matriz& mat);//Soma duas matrizes
    friend Matriz operator * (Matriz& mat1,Matriz& mat2);//Multiplica duas matrizes
    Matriz& operator ++();//incrementa em 1 os elementos da matriz

};

#endif /* MATRIZ_H */
