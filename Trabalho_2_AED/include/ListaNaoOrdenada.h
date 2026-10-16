#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"
#include <string>

class ListaNaoOrdenada
{
    public:
        ListaNaoOrdenada(int _tam);
        ~ListaNaoOrdenada();
        int InserirNoFinal(int _id, string _nome, int _idade);
        int InserirNoInicio(int _id, string _nome, int _idade);

        int InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        int RemoverPrimeiro();
        int RemoverUltimo();
        int RemoverPeloID(int id_remova_me);

        int BuscarPeloID(int id_buscado) const;

        int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade);

        //int AlterarPeloID(int _id, int _idade, string _nome, int _carga_horaria, string _especialidade, float _salario); <-implementar mais tarde

        void ImprimirLista() const;
    private:
        int tam;
        int ocupadas;
        Elemento** vetor;
};

#endif // LISTANAOORDENADA_H
