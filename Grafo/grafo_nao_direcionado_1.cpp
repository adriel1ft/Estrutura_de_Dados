#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using  std::vector;
using  std::string;
using  std::cout;
using  std::endl;
using  std::unordered_map;

class Grafo {

private:
    unordered_map<string, vector<string>> grafo;


    public:
        void adicionarVertice(string vertice){
            if (grafo.find(vertice) == grafo.end()){
                grafo[vertice] = vector<string>();
            }
        }

    

};

/*
- unordered_map : classe contêiner associativo que armazena pares chaves-valor. Neste caso, está sendo usada para criar um mapeamento
entre strings (chaves) e vetores de strings (valores).

- grafo: nome da variável que representa o unordered map

- cada chave no unordered_map representa um vértice no grafo

- unordered_map<string, vector<string>> grafo está declarando uma estrutura de dados que pode ser usada para representar um grafo não direcionado, onde cada vértice é uma string e as arestas são representadas por conexões entre vértices no vetor de strings associado a cada vértice. Essa estrutura permite que você armazene e manipule informações sobre vértices e suas conexões em um grafo de forma eficiente.


*/