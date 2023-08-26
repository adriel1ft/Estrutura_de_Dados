#include <iostream>
#include <stack>

using std::cout; 
using std::endl; 
using std::stack;

int main(){
    stack <int> pilha;

    pilha.push(10);
    pilha.push(100);
    pilha.push(200);
    pilha.push(300);

    cout << "Conteudo da pilha: " << endl;

    while(!pilha.empty()){
        cout << pilha.top() << " ";
        pilha.pop(); //remove o elemento do topo

    }

cout << endl;

    return 0;

}