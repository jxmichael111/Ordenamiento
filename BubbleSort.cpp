#include <iostream>
#include <fstream>
#include <vector>

void bubbleSort(std::vector<float>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    
        if (!swapped)
            break;
    }
}

int main() {
    std::ifstream archivo("datos.txt");
    std::vector<float> numeros;
    float num;

    
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo!" << std::endl;
        return 1;
    }

    
    while (archivo >> num) {
        numeros.push_back(num);
    }
    archivo.close();

    
    bubbleSort(numeros);

    
    std::cout << "Números ordenados:" << std::endl;
    for (float n : numeros) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
