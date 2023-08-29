#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Fila{

    vector<int>elementos;
    int tamanho, frente, tras;

    public:
        Fila(int tam): tamanho(tam), frente(0), tras(-1) {elementos.resize(tam);} //resize aloca espaço no vetor para armazenar os elementos da fila.

    bool isFull(){
        return (tras == tamanho - 1);
    }

    bool isEmpty(){
        return (frente > tras);
    }

    void enqueue(int valor){
        if(isFull()){
            cout << "A lista está cheia. Impossivel adicionar novos elementos." << endl;
        } else {
            tras++;
            elementos[tras] = valor;
        }
    }

    void dequeue(){
        if (isEmpty()){
            cout << "A listá ja ta vazia, bebe.";
        } else {
            frente++;
        }
    }

    int Front(){
        if(isEmpty()){
             cout << "Girl, its full. Get out. " << endl;
             return -1;   
        }
        return elementos[frente];
    }


};

int main(){
    Fila fila(5);

    fila.enqueue(100);
    fila.enqueue(200);
    fila.enqueue(300);

    cout << "Elemento na frente: " << fila.Front() << endl;

    fila.dequeue();
    cout << "Elemento na frente após a remoção: " << fila.Front() << endl; 

    return 0;

}