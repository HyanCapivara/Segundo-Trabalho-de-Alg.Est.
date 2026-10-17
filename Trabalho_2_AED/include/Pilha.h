#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h"

class Pilha
{
    public:
        Pilha(int _tam):suporte(_tam){}
        ~Pilha(){}
        int empilhar(int _id, string _nome, int _idade);
        int empilhar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int desempilhar();
        void consultarTopo() const;
        void pilhaCheia();
        void pilhaVazia();
    private:
        ListaNaoOrdenada suporte;
};

#endif // PILHA_H
