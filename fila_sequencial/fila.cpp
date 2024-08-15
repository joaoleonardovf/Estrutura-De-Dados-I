#include "fila.h"
#include <iostream>

using namespace std;

FilaSeq::FilaSeq(){
    inicio = 0;
    fim = -1;
    tamMax = 100;
    nElementos = 0;
}

bool FilaSeq::vazia(){
    return (nElementos == 0);
}

bool FilaSeq::cheia(){
    return (nElementos == tamMax);
}

int FilaSeq::tamanho(){
    return nElementos;
}

int FilaSeq::primeiroElem(){
    if (vazia()){
        return -1; 
    }

    return dados[inicio];
}

bool FilaSeq::insereFim(int valor){
    if (cheia()){
        return false;
    }

    fim = (fim + 1) % tamMax; //incremento circular
    dados[fim] = valor;
    nElementos++;

    return true;
}

int FilaSeq::removeInicio(){
    if (vazia()){
        return -1;
    }

    int valor = primeiroElem();
    inicio = (inicio + 1) % tamMax; //incremento circular
    nElementos--;

    return valor;
}

void FilaSeq::imprimirFila() {
    if (vazia()) {
        cout << "A fila está vazia." << endl;
        return;
    }

    cout << "Elementos da fila:" << endl;
    for (int i = 0; i < nElementos; i++) {
        int pos = (inicio + i) % tamMax;  //incremento circular para acessar o elemento correto
        cout << "Posição " << (i + 1) << ": " << dados[pos] << endl;
    }
}

