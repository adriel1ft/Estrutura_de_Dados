#include <iostream>
#include <vector>
#include <queue>
#include <fstream> // lidar com operacoes do arquivo

using namespace std;

class Graph{
    int vertices; //number of vertices
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

    //construtor
public:
    Graph(int V): vertices(V){
        adjMatrix.resize(V, vector<int>(V,0)); //iniciliza a matriz de adj com zeros
        adjList.resize(V); //inicializa a lista de ajd como um vetor vazio p cada vertice

    }

    //adicionar vertices
    void addEdge(int u, int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS(int s, int t){
        vector<int> parent(vertices, -1); // vetor de pais para reconstruir o caminho
        vector<bool> visited(vertices, false); // vetor para controlar os vertices visitados

        queue<int> q; // fila para busca em largura
        q.push(s); //comeca a partir do vertice de origem s
        visited[s] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
        }
    }

};

