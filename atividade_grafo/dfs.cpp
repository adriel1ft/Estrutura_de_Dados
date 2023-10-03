#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int V) : vertices(V) {
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //get
    int getVertices() const {
        return vertices;
    }

    const vector<int>& getAdjList(int u) const{
        return adjList[u];
    }

    void DFS(int v_inicial) {
        vector<bool> visited(vertices, false);
        stack<int> s; //pilha vazia p rastrear os vertices

        s.push(v_inicial); //adiciona o v_inicial à pilha
    

//enqt a pilha n estiver vazia
        while (!s.empty()){
            int v_atual = s.top();
            s.pop();

    //se ainda n foi visitado, vai ser visitado agr
        if (!visited[v_atual]){
            cout << v_atual << " ";
            visited[v_atual] = true;
        }

        //procurando os vizinhos na lista de adj do vertice
        for(int vizinho: adjList[v_atual]){
            if (!visited[vizinho]){
                s.push(vizinho);
            }
        }
    }    
}

 // Destrutor para desalocação de recursos
    ~Graph(){
        adjList.clear();
    }

};

int main(){
    ifstream inputFile("arq.txt"); //abre no modo leitura
    int vertices, arestas;
    inputFile >> vertices >> arestas; //lendo os valores

    //criando instancia/objeto
    Graph graph(vertices);


    //le e adiciona as aresras ao grafo
    for(int i = 0; i < arestas; i++){
        int u, v;
        inputFile >> u >> v; //le a proxima aresta do arquivo
        graph.addEdge(u,v); //add a aresta ao grafo 
    }

    int s;
    cout << "Digite o vertice de origem: ";
    cin >> s ; //input do usuario

    cout << "Ordem de visita dos vertices: ";
    //chama o bfs
    graph.DFS(s);

    inputFile.close(); //fecha o arquivo
    return 0;

}