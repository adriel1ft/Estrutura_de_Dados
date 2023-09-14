class Grafo:
    def __init__(self): #construtor de uma classe em python
        self.grafo = {} #dicionario vazio que sera usado para representar grafo
    
    def adicionar_vertice(self, vertice):
        if vertice not in self.grafo:
            self.grafo[vertice] = []

    def adicionar_aresta(self, vertice1, vertice2):
        #Add uma aresta não direcionada entre vertice1 e vertice2
        if vertice1 in self.grafo:
            self.grafo[vertice1].append(vertice2)
        if vertice2 in self.grafo:
            self.grafo[vertice2].append(vertice1)
    
    def mostrar_grafo(self):
        for vertice in self.grafo:
            print(f"{vertice}: {self.grafo[vertice]}")
    

    #exemplo de uso

grafo = Grafo()

grafo.adicionar_vertice("A")
grafo.adicionar_vertice("B")
grafo.adicionar_vertice("C")
grafo.adicionar_vertice("D")

grafo.adicionar_aresta("A", "B")
grafo.adicionar_aresta("B", "C")
grafo.adicionar_aresta("C", "D")
grafo.adicionar_aresta("D", "A")

grafo.mostrar_grafo()
