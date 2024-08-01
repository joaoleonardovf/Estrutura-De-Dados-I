#include "listaSeq.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ListaSequencial lista;

    cout << (lista.vazia() ? "A lista está vazia" : "A lista não está vazia") << endl;

    cout << (lista.inserir(1, 14) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;
    cout << (lista.inserir(2, 5) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;
    cout << (lista.inserir(3, 210) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;
    cout << (lista.inserir(4, 81) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;

    int pos = lista.posicao(14);
    cout << "Elemento na posição 1 " 
         << ((pos == -1) ? "não encontrado." : ("encontrado foi: " + to_string(lista.obterElemento(1)))) << endl;

    pos = lista.posicao(5);
    cout << "Elemento na posição 2 " 
         << ((pos == -1) ? "não encontrado." : ("encontrado foi: " + to_string(lista.obterElemento(2)))) << endl;

    pos = lista.posicao(210);
    cout << "Elemento na posição 3 " 
         << ((pos == -1) ? "não encontrado." : ("encontrado foi: " + to_string(lista.obterElemento(3)))) << endl;

    pos = lista.posicao(81);
    cout << "Elemento na posição 4 " 
         << ((pos == -1) ? "não encontrado." : ("encontrado foi: " + to_string(lista.obterElemento(4)))) << endl;

    cout << (lista.modificarElemento(3, 190) ? "Elemento foi modificado" : "Não foi possível modificar o elemento") << endl;
    cout << "Elemento da posição 3 modificado: " << lista.obterElemento(3) << endl;

    cout << "Tamanho da lista: " << lista.tamanho() << endl;

    cout << "Retirando o elemento " << lista.retirar(1) << " da posição 1" << endl;

    cout << "Tamanho da lista após remoção: " << lista.tamanho() << endl;

    cout << (lista.cheia() ? "A lista está cheia" : "A lista não está cheia") << endl;

    lista.exibirLista();

    return 0;
}
