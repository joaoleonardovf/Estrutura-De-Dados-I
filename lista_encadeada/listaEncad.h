#pragma once

#include "node.h"

class ListaEncadeada {
private:
    No* cabeca;
    int tamanho;

public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool vazia();
    int obterTamanho();
    int obterElemento(int pos);
    bool modificarElemento(int pos, int dado);
    bool inserir(int pos, int dado);
    int retirar(int pos);
    void imprimirLista();
};
