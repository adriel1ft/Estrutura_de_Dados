#include <iostream>
#include <string>
#include <vector>

using namespace std;


void insertion_sort(vector<int>& v, int size){

    int i, atual ,j;


    for(i=1; i < size; i++){
        atual = v[i]; // valor atual que estamos analisando
        j = i - 1; // vai começar a comparar com os anteriores

        while(j>=0 && atual < v[j]){
            v[j+1] = v[j]; // move os elementos maiores para direita
            v[j] = atual; // insere o valor na posição correta
            j--; //vai andando pra frente (esquerda) pra fzr as comparacoes

        }

    }
}

int main(){

    vector<int> my_vector = {5,1,42,3,7,2};

    //cout << "Vetor original" << endl;

    int tam = my_vector.size();

    

    insertion_sort(my_vector, tam);


    for(int x=0; x < tam; x++){
        cout << "" << my_vector[x] << " ";
    } cout << endl;

    

    return 0;
}