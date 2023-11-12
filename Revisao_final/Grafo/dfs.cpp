#include <iostream>
#include <list>
#include <stack>
#include <vector>

//dfs se usa pilha
//dfs com lista estática

using namespace std;

//grafo direcionado
class Graph {
    int num_vertices;  //num de vertices
    list<int> *adj;

public:
    // construtor
    Graph(int n){
        this->num_vertices = n;
        adj = new list<int>[n]; //cada valor tem uma lista de adjacencia
    }

    void addAresta(int v, int u){
        adj[v].push_back(u);
    }

    //busca em profundidade
    //paramentro = vertice inicial a ser visitado
    void DFS(int atual){

        //marca todos os vertices como nao visitado
        //cria um vetor dinamico q armazenara booleano
        vector<bool> visited(num_vertices, false);

        //cria uma pilha
        stack<int> pilha;

        pilha.push(atual); //add atual à pilha
 
        while (!pilha.empty()){ //enqt pilha n vazia
            int atual = pilha.top();
            pilha.pop();

            if (!visited[atual]){
                cout << atual << " ";
                visited[atual] = true; //marca atual como visitado
            }
                //percorrer os vizinhos
            for(auto i = adj[atual].begin(); i != adj[atual].end(); i++){
                if (!visited[*i]){
                    pilha.push(*i);
                }
            }
        }
    }


    void BFS(int atual){

    }

};