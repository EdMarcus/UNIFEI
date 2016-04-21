/* PROBLEMA COM DESTRUTORES E SOBRECARGA DE OPERADORES BINÁRIOS
*
 * O problema ocorre com a destruição do objeto ao fazer uma sobrecarga de
 * operadores binários, visto que um dos objetos a trabalhar é excluído antes
 * de terminar o processo.
 * O destrutor funciona normalmente, sem a utilização de sobrecarga binária.
 * O mesmo problema não acontece com a sobrecarga de operador unário, pois só
 * usa um objeto.
 * Como pedido, terminei a função friend para fazer o teste, e o mesmo erro 
 * ocorre.
 * O conteúdo do destrutor foi comentado para desativá-lo.
 * As funções que ocorrem o problema descrito são: friend operator * e 
 * operator +.
 *
 * 
 * 
 * /

/* 
 * File:   main.cpp
 * Author: Édlon de Sá
 * e-mail: edlondesa@gmail.com
 *
 * Created on 18 de Abril de 2016, 16:10
 */

#include <cstdlib>

#include "Matriz.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Matriz teste1(3,3);
    teste1.insere();
    Matriz teste2(3,3);
    teste2.insere();
    /* Teste * */
    if(Multiplicavel(teste1, teste2)) {
        Matriz teste3(3,3);
        teste3 = teste1 * teste2;
        teste3.mostra();
    }
    else cout << "Matriz não multiplicável";
    
    /* Teste + */
    /*
     
     Matriz teste4(3,3);
     teste4= teste1 + teste2;
     teste4.mostra();
     
     */
    return 0;
}

