
class HashTable:
    def __init__(self,n): #self é o objeto, no caso, tabela
        self.size_1 = 10
        self.niv_1 = [None] * self.size_1
        self.size_2 = n //self.size_1
        for i in range(self.size_1):
            self.niv_1[i] = [None] * self.size_2 #lista de listas

    def Hash_1(self, key):
        return key % self.size_1
    
    def Hash_2(self, key):
        return key % self.size_2
    
    def insert(self, key, value):
    
        # as funções devem ser chamadas a partir do próprio objeto
        index_1 = self.Hash_1(key) #index da lista de nivel 1
        index_2 = self.Hash_2(key) #index da lista de nivel 2
    
        if self.niv_1[index_1][index_2] is None:
            self.niv_1[index_1][index_2] = [] #cria a lista de nivel 2
        self.niv_1[index_1][index_2].append((key,value)) #adiciona o par chave-valor

      
    # buscar a partir da chave
    def search_by_key(self, key):
        #Inserir objeto com chave única
        index_1 = self.Hash_1(key) #index da lista de nivel 1
        index_2 = self.Hash_2(key) #index da lista de nivel 2

        if self.niv_1[index_1][index_2] is not None:
            data = self.niv_1[index_1][index_2]
            if data: #verifica se o dado n ta vazio
                result = f'Nivel 1, indice {index_1}: Nivel 2 indice {index_2}: {data}'
                return result
            return None

    # buscar a partir do valor
    def search_by_value(self, value_to_find):
        for index_1, niv_2 in enumerate(self.niv_1): #iteração pela tabela
            for index_2, data in enumerate(niv_2):
                if data: #verifica se o dado n ta vazio
                    for key, value in data:
                        if value == value_to_find:
                            return {
                                "Nome": value,
                                "Chave": key,
                                "Posicao": f"Nivel 1: indice {index_1}, Nivel 2: indice {index_2}"
                            }
                            
        return None
    
    def remove_by_value(self, value_to_remove):
        for index_1, niv_2 in enumerate(self.niv_1): #iteração pela tabela
            for index_2, data in enumerate(niv_2):
                if data:
                    for i, (key,value) in enumerate(data):
                        if value == value_to_remove:
                            del data[i] #remove o par chave-valor
                            return f'Aluno(a) "{value_to_remove}" removido(a) com sucesso.'
        return f'Aluno(a) "{value_to_remove}" nao encontrado(a) na tabela.'

    def print_table(self):
        for index_1,niv_2 in enumerate(self.niv_1): 
            for index_2, data in enumerate(niv_2):
                if data:
                    keys, values = [], []
                    for key, value in data:
                        keys.append(key)
                        values.append(value)
                    keys_str = f"[{', '.join(map(str, set(keys)))}]"  # convertendo as chaves em uma única string com chaves únicas  
                    values_str = ', '.join(values) 
                    print(f'Nivel 1, indice {index_1}: Nivel 2 indice {index_2}: Chave: {keys_str}, Valores: {values_str}')


