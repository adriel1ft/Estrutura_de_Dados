#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    std::string file_name = "instancias-num/num.10000.2.in"; 
    vector<int> numbers; // Vamos utilizar vetor

    // Abra o arquivo para leitura
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Nao foi possivel abrir o arquivo." << std::endl;
        return 1;
    }

    int number;
    int count = 0;


    while( file >> number && count < 10){
        numbers.push_back(number);
        count++
    }

    int size = numbers.size();

    cout << "size = " << size << endl;

    // Feche o arquivo
    file.close();

    return 0;
}
