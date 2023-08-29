#include <iostream>

//Lista Encadeada Dupla

struct No {
  char data;
  No *prev;
  No *next;
    //Construtor de Nó
    No(char value, No* p = nullptr, No* ne = nullptr): data(value), prev(p), next(ne){}
};

using std::cout;
using std::endl;

class LED { // LISTA ENCADEADA DUPLA
  No *head;

public:
  LED() { // Contrutor que inicializa o nó tendo a cabeca vazia
    head = nullptr;
  }

  // Função para remover  um nó específico
  void removeAuxNo(char aux){
   No* NoAtual = head;

   while (NoAtual!=nullptr){
    if(NoAtual->data == aux){

    }
   }
  }
  

  void addToBack(char value) { //adding elements do the list
    No* newNo = new No{
        value, nullptr,
        nullptr}; // criando um novo objeto No. value = valor armazenado em
                  // "data", prev e next são inicializados como nullptr,
                  // indicando que ainda não estão conectados a outros nós.
  if(head == nullptr){head = newNo;}
else {
  No* Atual = head; //apontando pro �ltimo valor adicionado
  while (Atual->next != nullptr){
    Atual = Atual->next;
  }
  Atual->next = newNo; //aqui � quando o primeiro next e prevo s�o set
  newNo->prev = Atual;

}  
  }

  No* getHead() const {
    return head;
  }

  //Função para imprimir a lista (apenas para exemplo)
    void printList(){
        No* current = head;
        while (current != nullptr){
            cout << current->data << "";
            current = current->next;
        }
        cout << endl;
    }

};

int main() { 
    LED list;

    //Adiciona elementos de exemplo
    list.addToBack(3);
    list.addToBack(2);
    list.addToBack(1);

    cout << "Lista original: ";
    list.printList();

    return 0;
}