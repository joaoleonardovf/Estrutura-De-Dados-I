#include <iostream>
#include "listaEncad.h"

using namespace std;

int main() {
    ListaEncadeada listaenc;

    cout << (listaenc.vazia() ? "A lista está vazia" : "A lista não está vazia") << endl;

    cout << (listaenc.inserir(1, 2019) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;
    cout << (listaenc.inserir(2, 22) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;
    cout << (listaenc.inserir(3, 9) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;
    cout << (listaenc.inserir(4, 81) ? "Elemento foi inserido" : "Não foi possível inserir o elemento") << endl;

    cout << "A lista atualmente é esta: ";
    listaenc.imprimirLista();
    cout << "Tamanho da lista: " << listaenc.obterTamanho() << endl;

    int pos1 = listaenc.obterElemento(1);
    cout << "Elemento na posição 1 "
         << ((pos1 == -1) ? "não encontrado." : ("encontrado foi: " + to_string(listaenc.obterElemento(1)))) << endl;

    int pos2 = listaenc.obterElemento(2);
    cout << "Elemento na posição 2 "
         << ((pos2 == -1) ? "não encontrado." : ("encontrado foi: " + to_string(listaenc.obterElemento(2)))) << endl;

    int pos3 = listaenc.obterElemento(3);
    cout << "Elemento na posição 3 "
         << ((pos3 == -1) ? "não encontrado." : ("encontrado foi: " + to_string(listaenc.obterElemento(3)))) << endl;

    int pos4 = listaenc.obterElemento(4);
    cout << "Elemento na posição 4 "
         << ((pos4 == -1) ? "não encontrado." : ("encontrado foi: " + to_string(listaenc.obterElemento(4)))) << endl;

    cout << (listaenc.modificarElemento(3, 190) ? "Elemento foi modificado" : "Não foi possível modificar o elemento") << endl;
    cout << "Elemento da posição 3 modificado: " << listaenc.obterElemento(3) << endl;

    cout << "Retirando o elemento " << listaenc.retirar(1) << " da posição 1" << endl;
    cout << "Tamanho da lista após remoção: " << listaenc.obterTamanho() << endl;
    cout << "Lista após remoção: ";
    listaenc.imprimirLista();

    cout << "Retirando o elemento " << listaenc.retirar(3) << " da posição 3" << endl;
    cout << "Tamanho da lista após remoção: " << listaenc.obterTamanho() << endl;
    cout << "Lista após remoção: ";
    listaenc.imprimirLista();

    cout << (listaenc.vazia() ? "A lista está vazia" : "A lista não está vazia") << endl;

    return 0;
}
