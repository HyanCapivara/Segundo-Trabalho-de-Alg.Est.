#include "Fila.h"
#include <iostream>

int Fila::enfileirar(int _id, string _nome, int _idade){
    return suporte.InserirNoFinal(_id, _nome, _idade);
}

int Fila::enfileirar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    return suporte.InserirNoFinal(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
}

int Fila::desenfileirar(){
    return suporte.RemoverPrimeiro();
}

void Fila::consultarInicio() const{
    if(suporte.getOcupadas() == 0)
        cout << "fila vazia" << endl;
    else
        suporte.getVetor(0)->imprimirInfo();
}

void Fila::filaCheia(){
    int temp = suporte.getTam();
    for(int i = suporte.getOcupadas(); i < temp; i++)
        suporte.InserirNoFinal(i, "generico", i);
}

void Fila::filaVazia(){
    int temp = suporte.getOcupadas();
    while(temp>0){
        suporte.RemoverUltimo();
        temp--;
    }
}
