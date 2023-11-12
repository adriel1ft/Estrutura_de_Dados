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
        tamMax = 5;
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

    int tamanho(){
        return nElementos;
    }

    int primeiro(){
        if (IsEmpty())
            return -1;
        return vetor[inicio];
    }

    bool enfilar(int valor){
        if(IsFull()){
            return false;
        }
        fim = (fim + 1) % tamMax; //circularidade
        vetor[fim] = valor;
        nElementos++;
        return true;
    }

    int desenfilar(){
        if (IsEmpty())
            return -1;

        int valor_removido = primeiro();
        
        inicio = (inicio+1) % tamMax;

        nElementos--;

        return valor_removido;
    }

    void print_fila(){
        for(int i = 0; i < tamanho(); i++){
                cout << vetor[(inicio+i) % tamMax] << "|" ;
        }
        cout << endl;
    }
};

int main(){

    FilaSeq fila;

    fila.enfilar(5);
    fila.enfilar(4);
    fila.enfilar(95);
    fila.enfilar(7);
    fila.enfilar(99);

    cout << "valor removido: " << fila.desenfilar() << endl;

    fila.print_fila();

    

    fila.enfilar(10);

    fila.print_fila();

    cout << "primeiro da fila = " << fila.primeiro();
    return 0;
}