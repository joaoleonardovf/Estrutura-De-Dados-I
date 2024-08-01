#include "listaSeq.h"
#include <iostream>

using namespace std;

ListaSequencial::ListaSequencial() {
    tamAtual = 0;
    tamMaximo = 200;
}

bool ListaSequencial::vazia() {
    return (tamAtual == 0);
}

bool ListaSequencial::cheia() {
    return (tamAtual == tamMaximo);
}

int ListaSequencial::tamanho() {
    return tamAtual;
}

int ListaSequencial::obterElemento(int pos) {
    if (pos > tamAtual || pos < 1) { // posição inválida
        return -1;
    }
    return dados[pos - 1];
}

bool ListaSequencial::modificarElemento(int pos, int dado) {
    if (pos > tamAtual || pos < 1) { // posição inválida
        return false;
    }
    dados[pos - 1] = dado;
    return true;
}

bool ListaSequencial::inserir(int pos, int dado) {
    if (cheia() || pos > tamAtual + 1 || pos < 1) {
        return false;
    }
    for (int i = tamAtual; i >= pos; i--) {
        dados[i] = dados[i - 1];
    }
    dados[pos - 1] = dado;
    tamAtual++;
    return true;
}

int ListaSequencial::retirar(int pos) {
    if (pos > tamAtual || pos < 1) {
        return -1;
    }
    int dado = dados[pos - 1];
    for (int i = pos - 1; i < tamAtual - 1; i++) {
        dados[i] = dados[i + 1];
    }
    tamAtual--;
    return dado;
}

int ListaSequencial::posicao(int dado) {
    for (int i = 0; i < tamAtual; i++) {
        if (dados[i] == dado) {
            return i + 1;
        }
    }
    return -1;
}

void ListaSequencial::exibirLista() {
    if (vazia()) {
        cout << "A lista está vazia." << endl;
        return;
    }

    cout << "Elementos da lista:" << endl;
    for (int i = 0; i < tamAtual; i++) {
        cout << "Posição " << (i + 1) << ": " << dados[i] << endl;
    }
}