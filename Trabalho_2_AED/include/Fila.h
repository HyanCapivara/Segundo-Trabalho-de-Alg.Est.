#ifndef FILA_H
#define FILA_H

#include "ListaNaoOrdenada.h"

class Fila
{
    public:
        Fila(int _tam):suporte(_tam){}
        ~Fila(){}
        int enfileirar(int _id, string _nome, int _idade);
        int enfileirar(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int desenfileirar();
        void consultarInicio() const;
        void filaCheia();
        void filaVazia();
    private:
        ListaNaoOrdenada suporte;
};

#endif // FILA_H
