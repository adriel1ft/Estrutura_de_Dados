class GraphMatrix:
    def __init__(self,num_vertices):
        #inicializa o grafo com 0
        self.num_vertices = num_vertices
        self.graph = [[0]*num_vertices for _ in range(num_vertices)]

    def add_edge(self,u,v): #u e v são vertices
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.graph[u][v]= 1
            self.graph[v][u] = 1

    def remove_edge(self, u, v):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.graph[u][v] = 0
            self.graph[v][u] = 0

    def display(self):
        for row in self.graph:
            print(" ".join(map(str,row)))

g = GraphMatrix(4)
g.add_edge(0,2)
g.add_edge(0,3)
g.add_edge(1,2)

print("Matriz de Adjacencia:")
g.display()
