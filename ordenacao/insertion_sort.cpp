#include <iostream>
#include <vector>

using namespace std;

// Função de ordenação Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int aux = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = aux;
    }
}
    