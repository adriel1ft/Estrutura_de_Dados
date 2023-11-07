#include <iostream>
#include <vector>
#include <fstream>

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
        merge(v,inicio, meio,fim);
    }



}

int main() {
    string file_name = "num.1000.2.txt"; 
    vector<int> my_vector; // Vamos utilizar vetor

    // Abra o arquivo para leitura
    ifstream file(file_name);

    if (!file.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << std::endl;
        return 1;
    }

    int number;
    int count = 0;


    while( file >> number){
        my_vector.push_back(number);
        count++;
    }

    int tam = my_vector.size();
    
    cout << "Vetor original" << endl;

    for(int x=0; x < tam; x++){
        cout << "" << my_vector[x] << " ";
    } cout << endl;
    
    
    
    merge_sort(my_vector,0,tam-1);
    
    cout << "Vetor ordenado:" << endl;

    for(int x=0; x < tam; x++){
        cout << "" << my_vector[x] << " ";
    } cout << endl;
    



    // Feche o arquivo
    file.close();

    return 0;




    return 0;
}
