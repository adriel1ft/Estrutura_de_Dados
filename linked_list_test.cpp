#include <iostream>

class No{

public:
    int data;
    No* next;

    No(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList{
    public:
    No* cabeca;

        LinkedList(){
            cabeca = nullptr;
        }

        //add values a lista encadeada
        void append(int value){
            No* novoNo = new No(value);

            if(cabeca == nullptr){ //define a cabeça da lista. é basicamente o valor que estiver na frente de todo mundo.
                cabeca = novoNo;
            }

            No* current = cabeca; // criação do ponteiro current, que aponta para o primeiro nó da lista
            while(current->next != nullptr ){ //percorre até achar o últino nó
                current  = current->next;
            }
            current->next = novoNo;
        }
};

int main(){
    LinkedList lista;

    //Agora linkedList.head aponta para nullptr indicando que a lista está vazia

    return 0;
}