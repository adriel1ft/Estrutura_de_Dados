#include <iostream>

struct No {
    int dado;
    No* prox;
    No* ant;
};

class ListaDuplamenteEncadeadaCircular{
    No* cabeca;

public:
    ListaDuplamenteEncadeadaCircular(): cabeca(nullptr){}

    void inserirInicio(int valor){
        No* novo = new No{valor, nullptr, nullptr}; //alocar No

        if(cabeca == nullptr){
            novo->prox = novo;
            novo->ant = novo;
        } else {
            novo->prox = cabeca;
            novo->ant = cabeca->ant;
            cabeca->ant = novo;
            cabeca->ant->prox = novo; //o ultimo no da lista recebe como prox o novo no q ta sendo inserido

        }
    }
};