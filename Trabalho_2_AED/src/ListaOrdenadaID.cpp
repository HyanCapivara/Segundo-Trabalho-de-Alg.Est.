#include "ListaOrdenadaID.h"

#include <iostream>

ListaOrdenadaID::ListaOrdenadaID(int _tam)
{
    ocupadas = 0;
    tam = _tam;
    vetor = new Elemento*[tam];
}

ListaOrdenadaID::~ListaOrdenadaID()
{
    delete[] vetor;
}

int ListaOrdenadaID::BuscarPeloID(int ini, int fim, int id_buscado) const{
    if(ini < fim){
        int meio = (ini+fim)/2;
        if(vetor[meio]->getID() > id_buscado)
            return BuscarPeloID(meio+1, fim, id_buscado);
        else if(vetor[meio]->getID() < id_buscado)
            return BuscarPeloID(ini, meio-1, id_buscado);
        else
            return meio;
    }
    return ini;
}

int ListaOrdenadaID::InserirOrdenadamente(int _id, string _nome, int _idade){
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    int pos_ins = BuscarPeloID(0, ocupadas-1, _id);

    for(int i = ocupadas; i > pos_ins; i++)
        vetor[i] = vetor[i-1];

    vetor[pos_ins] = new humano(_id, _nome, _idade);
    ocupadas++;

    return 1;
}

int ListaOrdenadaID::InserirOrdenadamente(int _id, string _nome, int _idade, string _especialidade, float _salario, int _carga_horaria){
    if(ocupadas == tam){
        cout << "lista cheia!" << endl;
        return -1;
    }

    int pos_ins = BuscarPeloID(0, ocupadas-1, _id);

    for(int i = ocupadas; i > pos_ins; i++)
        vetor[i] = vetor[i-1];

    vetor[pos_ins] = new professor(_id, _nome, _idade, _especialidade, _salario, _carga_horaria);
    ocupadas++;

    return 1;
}

int ListaOrdenadaID::RemoverPrimeiro(){ //mesmo método da lista desordenada, vou pensar em dar isso aqui de herança...
    if(ocupadas == 0){
        cout << "lista vazia" << endl;
        return -1;
    }

    delete vetor[0];
    for(int i = 0; i < ocupadas; i++) vetor[i] = vetor[i+1];
    ocupadas--;
    cout << "elemento removido" << endl;
    return 1;
}

int ListaOrdenadaID::RemoverUltimo(){ //idem
    if(ocupadas == 0){
        cout << "lista vazia" << endl;
        return -1;
    }

    delete vetor[ocupadas-1];
    ocupadas--;
    cout << "elemento removido" << endl;
    return 1;
}

int ListaOrdenadaID::RemoverPeloID(int id_remova_me){
    int pos_rem = BuscarPeloID(0, ocupadas-1, id_remova_me);

    if(pos_rem >= ocupadas || vetor[pos_rem]->getID() != id_remova_me){
        cout << "ID nao encontrado" << endl;
        return -1;
    }

    delete vetor[pos_rem];

    for(int i = pos_rem; i < ocupadas; i++)
        vetor[i] = vetor[i+1];

    return 1;
}

int ListaOrdenadaID::AlterarPeloID(int id_buscado, int _id, string _nome, int _idade){
    if(RemoverPeloID(id_buscado) == 1){
        InserirOrdenadamente(_id, _nome, _idade);
        return 1;
    }

    return -1;
}

void ListaOrdenadaID::ImprimirLista() const{
    for(int i = 0; i < ocupadas; i++){
        vetor[i]->imprimirInfo();
    }
}
