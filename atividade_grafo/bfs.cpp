#include <iostream>
#include <vector>
#include <queue>
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

    void BFS(int s, int t) {
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);

        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) { //enqt fila não estiver vazia
            int u = q.front(); /*pega o vertice atual. vertice u eh oq ta sendo processado neste
            momento no BFS*/
            q.pop(); /*remove o primeiro elemento (vertice atual) da fila.
            ele eh removido para evitar visitá-lo novamente*/

            for(int v: adjList[u]){ /* itera sobre todos os vertices adj ao vertice atual 'u' 
            usando a Lista de Adjacência*/
                if(!visited[v]){ //verifica se o vertice nao foi visitado ainda
                    q.push(v); /*se o vertice 'v' n foi visitado, ele é adicionado a fila q.
                    isso sgnf que o vertice v sera processado em uma iteracao posterior do loop do bfs*/
                    visited[v] = true; //marca o vertice v como visitado
                    parent[v] = u; //mantem um registro do vertice 'u' como pai do vertice 'v'.
                    //essa info   eh usada para reconstruir o caminho entre 
                }
            }
        }

        if(!visited[t]){ // se t n for visitado a partir de s
            cout << "Nao ha caminho entre os vertices." << endl;

        } else { // se o vertice de destino foi visitado 
            vector<int> path; //vetor para armazenar o caminho entre vetores
            int current = t; /*variavel com o valor do vertice do destino 't'.
            vai rastrear o caminho de tras para frente. do destino a origem*/
            while(current != -1){ //percorre os vertices pais
                path.push_back(current); /*vertice atual 'current' eh adicionado ao vetor path
                isso constroi o caminho do vertice de destino ao vertice de origem*/

                current = parent[current]; //A variável current é atualizada para o pai do vértice atual, permitindo que o loop continue retrocedendo pelo caminho.
            }

            cout << "Caminho entre os vertices " << s << " e " << t << ": ";
            //percorrer path de trás pra frente
            for(int i = path.size() - 1; i >=0; i--){
                cout << path[i];
                if(i != 0) cout << "->"; //tds tem isso menos o do indice 0
            }
            cout << endl;
        } 


        
        
        }

        // Destrutor para desalocação de recursos
        ~Graph(){
            adjList.clear();
        }


};

int main(){
    ifstream inputFile("arq.txt"); //abre no modo leitura
    int vertices, edges;
    inputFile >> vertices >> edges; //lendo os valores

    //criando instancia/objeto
    Graph graph(vertices);


    //le e adiciona as aresras ao grafo
    for(int i = 0; i < edges; i++){
        int u, v;
        inputFile >> u >> v; //le a proxima aresta do arquivo
        graph.addEdge(u,v); //add a aresta ao grafo 
    }

    int s,t;
    cout << "Digite o vertice de origem e o vertice de destino: ";
    cin >> s >> t; //input fo usuario

    //chama o bfs
    graph.BFS(s,t);

    inputFile.close(); //fecha o arquivo
    return 0;

}