#include "Elemento.h"
#include <iostream>

Elemento::Elemento(int _id)
{
    ID = _id;
}

Elemento::~Elemento()
{
}

int Elemento::getID() const{return ID;}

humano::humano(int _id, string _nome, int _idade):Elemento(_id){
    nome = _nome;
    idade = _idade;
}

void humano::imprimirInfo() const{
    cout << nome << " " << idade << endl;
}

int humano::getIdade() const{return idade;}
string humano::getNome() const{return nome;}

professor::professor(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria):humano(_id, _nome, _idade){
    carga_horaria = _carga_horaria;
    salario = _salario;
    especialidade = _especialidade;
}

void professor::imprimirInfo() const{
    cout << getNome() << " " << getIdade() << " " << especialidade << " " << salario << " " << carga_horaria << endl;
}
