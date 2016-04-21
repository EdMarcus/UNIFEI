/* 
 * File:   Matriz.cpp
 * Author: Édlon de Sá <edlondesa@gmail.com>
 * 
 * Created on 19 de Abril de 2016, 00:41
 */
#include <iostream>
#include "Matriz.h"

/* Construtor */
Matriz::Matriz(int l, int c) {
    linhas = l;
    colunas = c;
    matriz = new int*[l];
    for(int i = 0; i<l; i++){
        matriz[i]= new int[c];
    }   
}

/* Destrutor */
Matriz::~Matriz(){
//    for(int i=0; i<colunas; i++){
//       delete matriz[i];
//    }
//    delete []matriz;
}

/* Inserir dados na matriz */
void Matriz::insere(){
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            cout << "Inserir o valor [" << i+1 << "." << j+1 << "] da matriz: ";
            cin >> matriz[i][j];
        }
    }
}

/* Imprime a matriz dada */
void Matriz::mostra(){
    cout << "\nMatriz:\n\n";
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

/* Verifica se matriz é quadrada */
bool Matriz::matriz_quadrada(){
    if(this->linhas != this->colunas) return false;
    if(this->linhas == this->colunas) {
        return true;
    }
}

/* Retorna a soma da diagonal principal */
int Matriz::soma_diagonal(){
    int soma = 0;
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(i==j) soma+=matriz[i][j];
        }
    }
    return soma;
}

/* Retorna o maior valor da matriz */
int Matriz::maximo(){
    int aux = matriz[0][0];
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(aux<matriz[i][j]) aux=matriz[i][j];
        }
    }
    return aux;
}

/* Verifica se a matriz é triangular superior */
bool Matriz::Triangular_Superior(){
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(i>j){
                if(matriz[i][j]!=0) return false;
            }
        }
    }
    return true;
}

/* Verifica se a matriz é triangular inferior */
bool Matriz::Triangular_Inferior(){
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(i<j){
                if(matriz[i][j]!=0) return false;
            }
        }
    }
    return true;
}

/* Soma duas matrizes por sobrecarga */
Matriz Matriz :: operator + (Matriz& mat){
    Matriz aux(linhas, colunas);
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            aux.matriz[i][j]=this->matriz[i][j];
            aux.matriz[i][j]=aux.matriz[i][j]+mat.matriz[i][j];
        }
    }
    //this->mostra();
    return aux;
}

/* Multiplica duas matrizes com função friend */
Matriz operator * (Matriz& mat1, Matriz& mat2){
    Matriz aux(mat1.linhas, mat2.colunas);
    for(int i=0; i<mat1.linhas; i++){
        for(int j=0; j<mat2.colunas;j++){
            int somaProd = 0;
            for(int k=0; k<mat2.linhas;k++){
                somaProd+=mat1.matriz[i][k]*mat2.matriz[k][j];
            }
            aux.matriz[i][j] = somaProd;
        }
    }
    return aux;
}

/* Incrementa 1 a cada elemento da matriz por sobrecarga */
Matriz& Matriz :: operator ++ (){
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            matriz[i][j]=matriz[i][j]+1;
        }
    }
    return *this;
}

/* Verifica se a ordem de duas matrizes possibilita a multiplicação */
bool Multiplicavel(Matriz& m1, Matriz& m2){
    if(m1.colunas==m2.linhas) return true;
    else return false;
}