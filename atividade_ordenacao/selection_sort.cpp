#include <iostream>
#include <fstream>
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

                min_id = j; //atualizacao do min_id
            }     
        } 

        //trocando de lugar
        int aux = v[min_id];
        v[min_id] = v[i];
        v[i] = aux;

        /*cout << "Vetor apos troca " << i + 1 << ":"<<endl;
        cout << v[i]<< " eh o menor e trocou de lugar com " << v[min_id] << endl;
        for(int i=0; i< v.size(); i++){
        cout << "" << v[i] << " ";
        
        }*cout << endl << endl;*/
    }

}


int main() {
    std::string file_name = "num.1000.2.txt"; 
    vector<int> my_vector; // Vamos utilizar vetor

    // Abra o arquivo para leitura
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Nao foi possivel abrir o arquivo." << std::endl;
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
    
    
    
    selection_sort(my_vector);
    
    cout << "Vetor ordenado:" << endl;

    for(int x=0; x < tam; x++){
        cout << "" << my_vector[x] << " ";
    } cout << endl;
    



    // Feche o arquivo
    file.close();

    return 0;
}
