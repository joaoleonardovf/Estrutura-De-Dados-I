#include <iostream>
#include <vector>

using namespace std;

// Função de ordenação Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int aux;

    for (int i = 0; i < n - 1; i++) {
        int minIndice = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndice]) {
                minIndice = j;
            }
        }
        
        aux = arr[i];
        arr[i] = arr[minIndice];
        arr[minIndice] = aux;
    }
} 