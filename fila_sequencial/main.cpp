#include "fila.h"
#include <iostream>

using namespace std;

int main() {
    FilaSeq fila;

    cout << (fila.vazia() ? "A lista está vazia" : "A lista não está vazia") << endl;

    cout << (fila.insereFim(2019) ? "Um lemento foi inserido no fim da fila" : "A fila está cheia") << endl;
    cout << (fila.insereFim(22) ? "Um elemento foi inserido no fim da fila" : "A fila está cheia") << endl;
    cout << (fila.insereFim(9) ? "Um elemento foi inserido no fim da fila" : "A fila está cheia") << endl;
    cout << (fila.insereFim(81) ? "Um elemento foi inserido no fim da fila" : "A fila está cheia") << endl;

    cout << (fila.cheia() ? "A lista está cheia" : "A lista não está cheia") << endl;
    cout << "Tamanho da fila: " << fila.tamanho() << endl;

    cout << "Início da fila: " << fila.primeiroElem()  << endl;

    fila.imprimirFila();

    cout << "Removendo elemento " << fila.removeInicio() << " do início da fila" << endl;
    cout << "Tamanho da fila após remoção: " << fila.tamanho() << endl;

    cout << (fila.insereFim(99) ? "Um elemento foi inserido no fim da fila" : "A fila está cheia") << endl;
     
    cout << "Início da fila após alterações: " << fila.primeiroElem()  << endl;

    fila.imprimirFila();

    while (!fila.vazia()) {
        cout << "Removendo elemento: " << fila.removeInicio() << endl;
    }

    cout << (fila.vazia() ? "A fila está vazia" : "A fila não está vazia") << endl;

    return 0;
}
