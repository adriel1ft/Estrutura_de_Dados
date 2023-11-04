#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file_name = "num.10000.1.in"; // Substitua pelo nome do seu arquivo .in

    // Abra o arquivo para leitura
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Processar cada linha do arquivo
        // Faça aqui o processamento desejado, dependendo do formato dos dados
        // Neste exemplo, apenas imprimimos cada linha no console
        std::cout << line << std::endl;
    }

    // Feche o arquivo
    file.close();

    return 0;
}
