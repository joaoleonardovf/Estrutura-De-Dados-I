#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <chrono>

using namespace std;

void selectionSort(vector<int>& arr);
void insertionSort(vector<int>& arr);

// Função para ler um arquivo e armazenar os números em um vetor
void read_file(string& arquivo, vector<int>& arr) {
    ifstream file(arquivo);

    if (!file) {
        cout << "Não foi possível abrir o arquivo " << arquivo << endl;
        return;
    }

    int tamanho;
    file >> tamanho;
    arr.resize(tamanho);
    for (int i = 0; i < tamanho; i++) {
        file >> arr[i];
    }
}

// Função para imprimir o vetor
void imprmirArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso errado: " << argv[0] << " <tipo_de_ordenacao>  <arquivo_entrada> " << endl;
        return 1;
    }

    string tipo_de_ordenacao = argv[1];
    string filename = argv[2];
    vector<int> array;

    read_file(filename, array);

    if (array.empty()) {
        cout << "Erro ao ler o arquivo ou arquivo vazio." << endl;
        return 1;
    }

    clock_t comeco, fim;
    double duracao;

    if (tipo_de_ordenacao == "selectionSort") {
        comeco = clock(); 
        selectionSort(array);
        fim = clock(); 
    } else if (tipo_de_ordenacao == "insertionSort") {
        comeco = clock();
        insertionSort(array);
        fim = clock();
    } else {
        cout << "Ordenacao nao identificada: " << tipo_de_ordenacao << endl;
        return -1;
    }

    duracao = (double)(fim - comeco) / CLOCKS_PER_SEC; // Calculando a duração em segundos
    

    cout << "Array apos ordenacao: ";
    imprmirArray(array); 

    cout << "Levaram " << duracao << " segundos para a execucao da ordenacao." << endl; 

    return 0;
}