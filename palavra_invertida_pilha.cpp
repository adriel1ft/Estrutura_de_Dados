#include <iostream>
#include <stack>
#include <string>

using std::cout; 
using std::endl; 
using std::stack;
using std::string;

int main(){
    
    string palavra = "ESTE EXERCICIO E MUITO FACIL";

    stack <char> pilha;

    for(char letra : palavra){
        pilha.push(letra);
    }

    cout << "palavra ao contrario: " << endl;

    while(!pilha.empty()){
        cout << pilha.top() << " ";
        pilha.pop(); //remove  o elemento do topo. ngm fica no topo (tipo fora da caixa)
    }

    cout << endl;

    return 0;
}