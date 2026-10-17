#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada
{
    public:
        ListaNaoOrdenada(int _tam);
        ~ListaNaoOrdenada();

        //insercoes para humano
        virtual int InserirNoFinal(int _id, string _nome, int _idade);
        int InserirNoInicio(int _id, string _nome, int _idade);
        //int InserirNoInicio_Deslocamento(int _id, string _nome, int _idade);

        //insercoes para professor
        virtual int InserirNoFinal(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int InserirNoInicio(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        //int InserirNoInicio_Deslocamento(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        //as remoções são iguais para ambos as classes
        int RemoverPrimeiro();
        virtual int RemoverPrimeiroF();
        int RemoverUltimo();
        int RemoverPeloID(int id_remova_me);

        //as busca também é a mesma
        int BuscarPeloID(int id_buscado) const;

        //alteracao para humano
        //int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade);
        int AlterarPeloID(int id_buscado, string _nome, int _idade);

        //alteracao para professor
        //int AlterarPeloID(int id_buscado, int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        int AlterarPeloID(int id_buscado, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria);

        void ImprimirLista() const;

        int getOcupadas() const;
        void setOcupadas(int _ocupadas);
        int getTam() const;
        Elemento* getVetor(int pos) const;
        Elemento** getVetorPAlterar(int pos) const;

    private:
        int tam;
        int ocupadas;
        Elemento** vetor;
};

#endif // LISTANAOORDENADA_H
