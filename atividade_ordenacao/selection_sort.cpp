#include <iostream>
#include <vector>

using namespace std;

// Implementação do algoritmo de ordenação selection sort

void selection_sort(vector<int>& v){
    
    int size = v.size();

    for(int i=0; i < size - 1; i++){

        //min_id = indice com o menor valor 
        //começa com o min_id no indice 0, dps vai pra 1, 2, etc... to

        int min_id = i;

        //loop para percorrer os vizinhos à direita
        for(int j= i + 1; j < size; j++){

            if(v[min_id] > v[j]){

                min_id = j;
            }     
        } 
        int aux = v[min_id];
        v[min_id] = v[i];
        v[i] = aux;

        cout << "Vetor apos troca " << i + 1 << ":"<<endl;
        cout << v[i]<< " eh o menor e trocou de lugar com " << v[min_id] << endl;
        for(int i=0; i< v.size(); i++){
        cout << "" << v[i] << " ";
        
        }cout << endl << endl;
    }

}


int main(){

    vector<int> my_vector = {5,1,42,3,7};

    cout << "Vetor original" << endl;

    for(int x=0; x < my_vector.size(); x++){
        cout << "" << my_vector[x] << " ";
    } cout << endl;

    selection_sort(my_vector);


    

    return 0;
}