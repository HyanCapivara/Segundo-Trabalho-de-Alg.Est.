#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada
{
    public:
        ListaNaoOrdenada(int _tam);
        ~ListaNaoOrdenada();

        //insercoes para humano
        int InserirNoFinal(int _id, string _nome, int _idade);
        int InserirNoInicio(int _id, string _nome, int _idade);
        int InserirNoInicioF(int _id, string _nome, int _idade);

        //insercoes para professor
        int InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int InserirNoInicioF(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        //as remocoes dao na mesma
        int RemoverPrimeiro();
        int RemoverPrimeiroF();
        int RemoverUltimo();
        int RemoverPeloID(int id_remova_me);

        //as buscas tambem dao na mesma;
        int BuscarPeloID(int id_buscado) const;

        //alteracao para humano
        //int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade);
        int AlterarPeloID(int id_buscado, string _nome, int _idade);

        //alteracao para professor
        //int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        void ImprimirLista() const;

        int getOcupadas() const;
        int getTam() const;
        Elemento* getVetor(int pos) const;

    private:
        int tam;
        int ocupadas;
        Elemento** vetor;
};

#endif // LISTANAOORDENADA_H
