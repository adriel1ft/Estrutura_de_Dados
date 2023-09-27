import queue #fila

class Graph: #p construir o graf0
    #construtor, n = ordem da matriz, self refere ao próprio grafo
    def __init__(self,n): 
        self.num_vertices = n
        #criando matriz e lista vazia
        self.matrix = [[0 for _ in range(n) for _ in range(n)]]
        self.list = [[] for _ in range(n)]

    def print(self):
        print(self.matrix)
        print(self.list)
    
    def add_edge(self, u,v):

    
    #source = ponto de partida
    def bfs(self,source): 
        dist = [-1 for _ in range(self.num_vertices)]
        ant = [-1 for _ in range(self.num_vertices)]

        isVisited = [False for _ in range(self.num_vertices)]

        #declarando a fila
        Q = queue.Queue()

        #adicionando source
        Q.put(source)
