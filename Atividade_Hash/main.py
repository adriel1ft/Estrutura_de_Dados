from hash_table_2niveis import HashTable


def main():
    table = HashTable(20)

# ler dados do arquivo "alunos.txt"

    with open("alunos.txt", "r") as file:
        for line in file:
            chave, nome = line.strip().split()
            table.insert(int(chave),nome) #inserção na tabela

    # print da tabela
    print("*Tabela*")
    table.print_table()
    print("-------------------")

    # busca por valor
    print("*Exemplo de Busca por valor*")
    buscar_julia = table.search_by_value("Julia")
    print(buscar_julia)
    print("-------------------")

    # busca por chave
    print("*Exemplo de Busca por chave*")
    buscar_92 = table.search_by_key(92)
    print(buscar_92)
    print("-------------------")

    # remocao 
    print("*Exemplo de remocao de valor*")
    remover_ricardo = table.remove_by_value('Ricardo')
    print(remover_ricardo)
    print("-------------------")

    print("*Tabela depois da remocao*")
    table.print_table()
    print("-------------------")

    

if __name__ == "__main__":
    main()
