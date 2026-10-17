#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>

using namespace std;

class Elemento
{
    public:
        //construtores
        Elemento(int _id); //O único método para inserir ID's
        virtual ~Elemento(); //destrutor virtual já que vou usar um vetor com classes derivadas de elemento
        virtual void imprimirInfo() const = 0;
        int getID() const;
    protected:
        int ID;
    private:
};

class humano:public Elemento{
    public:
        humano(int _id, string _nome, int _idade);
        ~humano(){}
        void imprimirInfo() const;
        int getIdade() const;
        string getNome() const;
    private:
        string nome;
        int idade;
};

class professor:public humano{
    public:
        professor(int _id, string nome, int _idade, string _especialidade, float _salario, int _carga_horaria);
        ~professor(){}
        void imprimirInfo() const;
    private:
        int carga_horaria;
        float salario;
        string especialidade;
};

#endif // ELEMENTO_H
