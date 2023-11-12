#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Grafo {
    int vertices; // Quantidade de vértices
    vector<vector<int>> adjList;

public:
    Grafo(int V) : vertices(V) {
        adjList.resize(V);
    }

    void add_aresta(int u, int w) {
        adjList[u].push_back(w);
    }

    int get_vertices() {
        return vertices;
    }

    vector<int> get_adjList(int vertice) {
        return adjList[vertice];
    }


    void BFS(int s, int d, vector<int>& parent, vector<bool>& visited) {
        queue<int> fila;
        fila.push(s);
        visited[s] = true;

        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    fila.push(v);
                    parent[v] = u;

                    if (v == d) {
                        // Se o destino for alcançado, pare a BFS
                        while (!fila.empty()) {
                            fila.pop();
                        }
                        break;
                    }
                }
            }
        }
    }

    void menor_caminho(int s, int d) {
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);

        BFS(s, d, parent, visited);

        if (!visited[d]) {
            cout << "Não há caminho entre " << s << " e " << d << endl;
        } else {
            vector<int> path;
            int pred = d;

            while (pred != -1) {
                path.push_back(pred);
                pred = parent[pred];
            }

            // Vamos imprimir o caminho
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];

                if (i != 0) cout << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Grafo g(6);

    g.add_aresta(1, 3);
    g.add_aresta(1, 2);
    g.add_aresta(3, 6);
    g.add_aresta(3, 5);
    g.add_aresta(2, 4);
    g.add_aresta(2, 5);

    g.menor_caminho(1, 5);

    return 0;
}




