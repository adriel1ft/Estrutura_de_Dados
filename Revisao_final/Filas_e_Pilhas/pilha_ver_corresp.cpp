#include <iostream>
#include <stack>

using namespace std;

bool VerificarCorrespondencia(const string& expressao){
    stack<char> pilha;

    for(char c: expressao){
        if (c == '(' || c == '['){
            pilha.push(c);
        }   else if (c == ')' || c == ']'){
            if (pilha.empty()){
                return false;
            } else if ((c == ')' && pilha.top() == '(') || (c == ']' && pilha.top() == '[')){
                pilha.pop(); //encontrou a correspondencia
            } else {
                return false;
            }
        }

    }

    return pilha.empty();
    
}




int main() {
    // Exemplos de uso:
    std::cout << std::boolalpha;  // Para imprimir 'true' ou 'false' em vez de '1' ou '0'
    
    std::string expressao1 = "[2+(3-4)*6]";
    std::string expressao2 = "[(4 * 5)) +7]";

    std::cout << "Expressao 1: " << VerificarCorrespondencia(expressao1) << std::endl;  // Deve imprimir true
    std::cout << "Expressao 2: " << VerificarCorrespondencia(expressao2) << std::endl;  // Deve imprimir false

    return 0;
}