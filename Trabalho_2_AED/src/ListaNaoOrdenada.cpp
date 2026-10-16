#include "ListaNaoOrdenada.h"
#include <iostream>

using namespace std;

ListaNaoOrdenada::ListaNaoOrdenada(int _tam)
{
    tam = _tam;
    ocupadas = 0;
    vetor = new Elemento*[tam];
    cout << "Lista de tamanho " << tam << " criada com sucesso!" << endl;
}

ListaNaoOrdenada::~ListaNaoOrdenada()
{
    delete[] vetor;
    cout << "Lista eliminada" << endl;
}

int ListaNaoOrdenada::InserirNoFinal(int _id, string _nome, int _idade){
    if(ocupadas == tam){
        cout << "Lista cheia" << endl;
        return -1;
    }

    vetor[ocupadas] = new humano(_id, _nome, _idade);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoInicio(int _id, string _nome, int _idade){
    //Duas alternativas: mover inicio para o fim e inserir no inicio ou mover todos para frente inserir no fim. A primeira é mais barata mas é inapropriada para implementar pilhas
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    vetor[ocupadas] = vetor[0]; //1 jeito
    //for(int i = ocupadas; i > 0; i--) vetor[i] = vetor[i-1]; //2 jeito

    vetor[0] = new humano(_id, _nome, _idade);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(ocupadas == tam){
        cout << "Lista cheia" << endl;
        return -1;
    }

    vetor[ocupadas] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    //Duas alternativas: mover inicio para o fim e inserir no inicio ou mover todos para frente inserir no fim. A primeira é mais barata mas é inapropriada para implementar pilhas
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    //vetor[ocupadas] = vetor[0]; //1 jeito
    for(int i = ocupadas; i > 0; i--) vetor[i] = vetor[i-1]; //2 jeito

    vetor[0] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;
    return 1;
}

int ListaNaoOrdenada::RemoverPrimeiro(){
    //tambem tem duas alternativas. Ou troca com o ultimo e elimina ou elimina e move para cobrir o buraco
    if(ocupadas == 0){
        cout << "lista vazia" << endl;
        return -1;
    }

    delete vetor[0];

    //vetor[0] = vetor[ocupadas-1];

    for(int i = 0; i < ocupadas; i++) vetor[i] = vetor[i+1];
    ocupadas--;
    cout << "elemento removido" << endl;
    return 1;
}

int ListaNaoOrdenada::RemoverUltimo(){
    if(ocupadas == 0){
        cout << "lista vazia" << endl;
        return -1;
    }

    delete vetor[ocupadas-1];
    ocupadas--;
    cout << "elemento removido" << endl;
    return 1;
}

int ListaNaoOrdenada::RemoverPeloID(int id_remova_me){
    for(int i = 0; i < ocupadas; i++){
        if(vetor[i]->getID() == id_remova_me){
            delete vetor[i];
            vetor[i] = vetor[ocupadas-1];
            ocupadas--;
            cout << "elemento removido" << endl;
            return 1;
        }
    }

    cout << "elemento nao encontrado" << endl;
    return -1;
}

int ListaNaoOrdenada::BuscarPeloID(int id_buscado) const{
    for(int i = 0; i < ocupadas; i++){
        if(vetor[i]->getID() == id_buscado)
            return i;
    }

    return -1;
}

int ListaNaoOrdenada::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade){
    if(RemoverPeloID(id_buscado) == 1){
        InserirNoFinal(_id, _nome, _idade); //a escolha da insercao foi arbritaria
        cout << "Substituicao bem sucedida" << endl;
        return 1;
    }

    cout << "Nao foi possivel efetuar a substituicao" << endl;
    return -1;
}

void ListaNaoOrdenada::ImprimirLista() const{
    for(int i = 0; i < ocupadas; i++){
        vetor[i]->imprimirInfo();
    }
}
