#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Grafo{
    int vertices; //qtd de vertices
    vector<vector<int>> adjList;

    public:
        Grafo(int V): vertices(V){
            adjList.resize(V);
        }

    void add_aresta(int u, int w){
        adjList[u].push_back(w);
    }
    
    int get_vertices(){
        return vertices;
    }

    vector<int> get_adjList(int vertice){
        return adjList[vertice];
    }


    void BFS(int s, int d, vector<int>& parent, vector<bool>& visited){
        //vetores parent e visited
        /*vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);*/

        queue<int> fila;
        fila.push(s);
        visited[s] = true;

        while(!fila.empty()){
            int u = fila.front();
            fila.pop();

            for(int v: adjList[u]){
                if(!visited[v]){
                    visited[v] = true;
                    fila.push(v);
                    parent[v] = u;


                    if(v ==d){
                        while(!fila.empty()){
                        fila.pop();
                        }
                        break;
                    }
                    
                }
            }
        }
    }
    
    void caminho(int s, int d){

    vector<int> parent(vertices, -1);
    vector<bool> visited(vertices, false);
    int dist = 0;

    BFS(s, d, parent, visited);
    if(!visited[d]){
        cout << "Nao ha caminho entre " << s << "e " << d << endl;
    } else {
        vector<int> path;

        int pred = d; //vamos começar a visitar os predecessores a partir do destino

        while (pred != -1){
            path.push_back(pred); //adicionamos os predecessores no caminho. agr é de tras pra frente mas depois vamos printar o inverso
            pred = parent[pred];
            dist++;
        }

        //vamos printar o caminho
        for( int i = path.size() - 1; i >=0; i--){
            cout << path[i];

            if(i != 0) cout << "-> " ;
        }
        //cout << 

        cout << "\ndistancia: " << dist << endl;
    }
}



};

int main(){
    Grafo g(6);

    g.add_aresta(1,2);
    g.add_aresta(1,3);
    g.add_aresta(3,5);
    g.add_aresta(3,6);
    g.add_aresta(2,4);
    g.add_aresta(2,5);

    g.caminho(1,5);

    //return 0;
}