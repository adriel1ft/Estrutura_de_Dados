#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int>& v, int inicio, int meio, int fim){

    //array auxiliar
    int* aux = new int[v.size()]; // alocando dinamicamente

    //transfere os elementos para array auxiliar
    for(int i = inicio; i<=fim; i++){
        aux[i] = v[i];
    }

    int i, j, k;
    i = inicio; //inicio de v
    j = meio + 1;
    k = inicio; // inicio

    while ( i <= meio && j <= fim){

        //comparacao entre os arrays

        if (aux[i] <= aux[j]){
            v[k] = aux[i];
            i++;
        } else {
            v[k] = aux[j];
            j++;
        }
        k++; // vai para proxima posicao de k
    }

    // adicione o restante dos elementos da primeira metade (se houver)
    while (i <= meio) {
        v[k] = aux[i];
        i++;
        k++;
    }
    // adicione o restante dos elementos da segunda metade (se houver)
    while (j <= fim){
        v[k] = aux[j];
        j++;
        k++; 
    }



    delete[] aux;

}

void merge_sort(vector<int>& v, int inicio, int fim){

    if (inicio >= fim){
        return;
    }

    else {
        int meio = (inicio + fim) / 2;
        merge_sort(v, inicio, meio); //primeira metade
        merge_sort(v, meio+1, fim);
    }



}

int main(){

    vector<int> my_vector = {2,1,9,7,5};

    int tam = my_vector.size();

    merge_sort(my_vector,0,tam -1);

    for(int x=0; x < tam; x++){
        cout << "" << my_vector[x] << " ";
    } cout << endl;




    return 0;
}