#include <stdio.h>
#include <stdlib.h>

/*
    Tabela Hash com Lista Encadeada
*/

// 2 * 15 = 30
//primo + prox = 31

#define TAM 31

typedef struct no{
    int chave;
    struct no *prox;
} No;

typedef struct{
    No *inicio;
    int tam;
} Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserirLista(Lista *l, int valor){
    No *novo = malloca(sizeof(No));

    if (novo){
        novo->chave = valor;
        novo->prox = l->inicio;
        l->inicio = novo;

    }else
        printf("\n\tErro ao alocar memoria!\n");
}

int buscarLista(Lista *l, int valor){
    No *aux = l->inicio;
    while (aux && aux ->chave != valor)
        aux = aux->prox;
    
    if (aux != 0)
        return aux->chave;
    return 0;

}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    printf("Tam: %d: ", l->tam);

    while(aux){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

void inicializarTabela(int t[]){
    int i;

    for(int i=0; i < TAM; i++){
        t[i] = 0; //0 n faz parte do conjunto

    }
}

//funcao hash ou espelhamento
int funcaoHash(int chave){ 
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);

    /*se ocorrer colisao, faz o reespelhamento
    se o próximo indice nao estiver vazio*/
    while (t[id] != 0){
        id = funcaoHash(id+1); 
    }

    t[id] = valor;
}

void print(int t[]){
    for(int i=0; i<TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != 0){
        if (t[id] == chave)
            return id;
        else
            id = funcaoHash(id+1);
    }
    return 0;
}

void remover(int t[], int chave){
    int id = busca(t,chave);
    if (id != 0){
        t[id] = -1; // -1 = eliminado
    }
}

int main(){
    int opcao, valor, retorno, tabela[TAM];

    inicializarTabela(tabela);

    do{
        printf( "\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t4 - Remover\n\t4- Print");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\tQual valor deseja inserir? ");
                scanf("%d,", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("\tQual valor deseja buscar? ");
                scanf("%d,", &valor);
                retorno = busca(tabela, valor);
                if(retorno != 0)
                    printf("\tValor encontrado no indice: %d\n", retorno);
                else
                    printf("\tValor nao encontrado!\n");
                break;
            case 3:
                printf("Deseja remover qual valor?");
                scanf("%d,", &valor);
                remover(tabela, valor);
            break;
            case 4:
                print(tabela);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);


    return 0;
}