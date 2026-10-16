#include <iostream>
#include <string>
#include "ListaNaoOrdenada.h"

using namespace std;


int main(){

    ListaNaoOrdenada l1(50);

    for(int i = 0; i < 10; i++){
        l1.InserirNoFinal(i, "a", i);
        l1.InserirNoFinal(i+10, "b", i+10, "c", 2.5, i+10);
        l1.InserirNoInicio(i+20, "A", i+20);
        l1.InserirNoInicio(i+30, "B", i+30, "C", 5, i+30);
    }

    l1.ImprimirLista();

    return 0;
}
