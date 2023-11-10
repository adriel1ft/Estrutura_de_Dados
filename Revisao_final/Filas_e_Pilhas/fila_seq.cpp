#include <iostream>

using namespace std;

class FilaSeq{
    int *vetor, inicio, fim, nElementos, tamMax;
    //*vetor eh um array dinamico, pois estamos em c++

public:
    //construtor
    FilaSeq(){
        inicio = 0;
        fim = -1;
        nElementos = 0;
        tamMax = 100;
        vetor = new int[tamMax];
    }

    //destrutor para liberar a memoria alocada dinamicamente
    ~FilaSeq(){
        delete[] vetor;
    }

    //funcoes

    //funcoes para verificar vazia
    bool IsEmpty(){
        if (nElementos == 0){
            return true;
        } else {
            return false;
        }
    }

    //verificar se cheia

    bool IsFull(){
        if (nElementos == tamMax){
            return true;
        } else {
            return false;
        }
    }
};