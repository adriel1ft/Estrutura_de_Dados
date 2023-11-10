#include <iostream>

using namespace std;

class No {
public:
    int valor;
    No* prox;


    No(int v): valor(v), prox(nullptr){}

};

class ListaEncadeada {

public:  
    No* cabeca;


    ListaEncadeada(){
        this->cabeca = nullptr;
    };

    void add(int valor){
        No* novoNo = new No(valor);

        if (cabeca == nullptr){
            cabeca = novoNo;
        } else {
            No* atual = cabeca;
            //visitando os nós ate achar um que aponte para vazio
            while(atual->prox != nullptr){
                atual = atual->prox;
            }
            atual->prox = novoNo;
        }

    }


    //funcao para contar quantos elementos iguais a v existem
    int count(int v){
        No* atual = cabeca;
        int count = 0;

        while(atual->prox != nullptr){
            atual = atual->prox;
            if(atual->valor == v){
                count ++;
            }
        }

        return count;
    }

    void remover_iguais(ListaEncadeada l,int v){ //valor q eu quero remover

        if(v == cabeca->valor){
            No* temp = cabeca;
            cabeca->valor = v;
            delete temp;
            cout << "Valor " << v << "removido da lista." << endl;          
        }else{

        No* aux = cabeca;

        //remover todos os elementos iguais a v que possuem na lista:
        int qtd = l.count(v); //qtd de repetidos

        for(int i=0; i<qtd; i++){

        while(aux->prox->valor != v){
            aux = aux ->prox;
            }
            No* aux2 = aux->prox; //aux->prox eh quem eu quero deletar. vai ter um X -> Y. aux é X e aux->prox eh  Y
            aux->prox = aux->prox->prox;
            delete aux2;
            }
        }

    }



    void listar(){
        if (cabeca == nullptr){
            cout << "Não há elementos na lista";
        }else {
            cout << "Elementos da lista encadeada: " << endl;
            
            
            No* atual = cabeca;

            cout << atual->valor << "-> ";

            //visitando os nós ate achar um que aponte para vazio
            while(atual->prox != nullptr){
                atual = atual->prox;
                cout << atual->valor << "-> ";
                
            }
            cout << endl;
            

        } 
        
        
        
    }
};

int main(){

    ListaEncadeada lista;
    lista.add(15);
    lista.add(10);
    lista.add(3);
    lista.add(49);
    lista.add(17);
    lista.add(18);
    lista.add(17);
    lista.add(99);
    lista.add(17);

    cout << "Lista antes da remocao: " << endl; 
    lista.listar();

    lista.remover_iguais(lista,17);

    cout << "Lista depois da remocao: " << endl;
    lista.listar();

    return 0;

}