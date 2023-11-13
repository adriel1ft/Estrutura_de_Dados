#include <iostream>

using namespace std;

class No {
    int valor;
    No* prox;

public:
    No(int v): valor(v), prox(nullptr){}

    int get_valor(){
            return valor;
        }

    void set_valor(int v){
        valor =v;
    }

    No* get_prox(){
        return prox;
    }

    void set_prox(No* p){
        prox = p;
    }
};

class ListaEncadeada {
public:
    No* cabeca;

    ListaEncadeada(){
        this->cabeca = nullptr;
    }

    void add_ordenado(int a){ //b = valor adicionado
        No* novoNo = new No(a);

        if (cabeca == nullptr){
            cabeca = novoNo;
    } else {

        No* atual = cabeca;
        No* anterior = nullptr;

        while (atual != nullptr && atual->get_valor() < a) {
            anterior = atual;
            atual = atual->get_prox();
        }

        if (anterior == nullptr){
            //se for menor q a cabeca
            novoNo->set_prox(cabeca);
            cabeca = novoNo;
        } else {
            //insercao entre nós existentes
        anterior->set_prox(novoNo);
        novoNo->set_prox(atual);
            }
        }
    }

    void listar(){
        if (cabeca == nullptr){
            cout << "Não há elementos na lista";
        }else {
            // cout << "Elementos da lista encadeada: " << endl;
            
            
            No* atual = cabeca;

            //cout << atual->get_valor() << "-> ";

            //visitando os nós ate achar um que aponte para vazio
            while(atual != nullptr){
                cout << atual->get_valor() << "-> ";
                atual = atual->get_prox();
                
                
            }
            //cout << endl;
            

        } 
}
};

int main(){

    ListaEncadeada lista;
    lista.add_ordenado(15);
    lista.add_ordenado(10);
    lista.add_ordenado(3);
    lista.add_ordenado(49);
    lista.add_ordenado(17);
    lista.add_ordenado(18);
    lista.add_ordenado(17);
    lista.add_ordenado(99);
    lista.add_ordenado(17);

    cout << "Lista de Nos: " << endl; 
    lista.listar();

    return 0;
}

