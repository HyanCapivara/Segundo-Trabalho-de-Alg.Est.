#include <iostream>
#include <string>
#include "ListaNaoOrdenada.h"
#include "ListaOrdenadaID.h"
#include "Pilha.h"
#include "Fila.h"
#include "Geral.h"

/*Alterar pelo id deve alterar os dados associados a esse id ou colocar algo no lugar desse id?
A busca deve retornar as informações do id achado?
todos os metodos devem ficar retornando mensagens?*/

using namespace std;



int main(){
    int escolha, tam;

    cout << "Que estrutura gostaria de testar:\nLista (1)\nLista Ordenada (2)\nPilha (3)\nFila (4)\n->";
    cin >> escolha;
    while(escolha > 4 || escolha < 1){
        cout << "Escolha uma alternativa valida\n->";
        cin >> escolha;
    }
    cout << "Que tamanho voce deseja para a estrutura\n->";
    cin >> tam;
    while(tam <= 0){
        cout << "Favor escolher um tamanho positivo\n->";
        cin >> tam;
    }

    switch(escolha){
    case 1:
        glista(tam);
        break;
    case 2:
        glistaord(tam);
        break;
    case 3:
        gpilha(tam);
        break;
    case 4:
        gfila(tam);
        break;
    }


    return 0;
}
