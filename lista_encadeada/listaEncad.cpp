#include "listaEncad.h"
#include <iostream>

using namespace std;

ListaEncadeada::ListaEncadeada(){
    cabeca = nullptr;
    tamanho = 0;
}

ListaEncadeada::~ListaEncadeada() {
    No* atual = cabeca;

    while (atual != nullptr) {
        No* prox = atual->getProximo();
        delete atual;
        atual = prox;
    }
}

bool ListaEncadeada::vazia(){
    return (tamanho == 0);
}

int ListaEncadeada::obterTamanho() {
    return tamanho;
}

int ListaEncadeada::obterElemento(int pos) {
    No *aux = cabeca;

    if (vazia()) {
        cout << "Lista está vazia" << endl;
        return -1;
    }

    if (pos < 1 || pos > tamanho){
        cout << "Posição inválida" << endl;
        return -1;
    }

    for (int cont = 1; cont < pos; cont++){
        aux = aux->getProximo();
    }    

    return aux->getConteudo();
}

bool ListaEncadeada::modificarElemento(int pos, int dado){
    if (pos > tamanho || pos < 1) {
        cout << "Posição inválida" << endl;
        return false;
    }

    No* atual = cabeca;
    for (int i = 1; i < pos; i++) {
        atual = atual->getProximo();
    }
    
    atual->setConteudo(dado);
    return true;
}

bool ListaEncadeada::inserir(int pos, int dado){
    if((vazia()) && (pos != 1))
        return false;

    if (pos < 1 || pos > tamanho + 1) {
        cout << "Posicao inválida" << endl;
        return false;
    }

    if (pos == 1){ // insercao no inicio da lista
        // Insere novo elemento na cabeça da lista
        No* novoNo = new No(dado);

        novoNo->setProximo(cabeca);
        cabeca = novoNo;
        tamanho++;
        return true;

    } else if (pos == tamanho+1){ // inserção no fim
        No* novoNo = new No(dado);

        // Verifica se a lista está vazia
        if (cabeca == nullptr) {
            cabeca = novoNo; 
        } else {
            No* aux = cabeca;
            while (aux->getProximo() != nullptr) {
                aux = aux->getProximo();
            }
            aux->setProximo(novoNo);
        }

        tamanho++;
        return true;

    } else{ // inserção no meio da lista
        int cont = 1;
        No *novoNo = new No(dado);
        
        No *aux = cabeca;
        while ((cont < pos-1) && (aux != nullptr)){
            aux = aux->getProximo();
            cont++;
        }

        if (aux == nullptr){
            delete novoNo;
            return false;
        }

        novoNo->setProximo(aux->getProximo());
        aux->setProximo(novoNo);
        tamanho++;
        return true;
    }
}

int ListaEncadeada::retirar(int pos){
    if (vazia()) return -1; // Lista vazia

    if (pos < 1 || pos > tamanho) {
        cout << "Posicao inválida" << endl;
        return -1;
    }

    if (pos == 1){ // remoção do elemento da cabeça da lista
        No *aux = cabeca;
        int dado = aux->getConteudo();
       
        cabeca = aux->getProximo();

        delete aux;
        tamanho--;
        return dado;

    } else{ // remoção em outro lugar da lista
        No* atual = cabeca;
        No* antecessor = nullptr;
        int dado = -1;
        int cont = 1;

        // Encontra o nó na posição especificada
        while (cont < pos && atual != nullptr) {
            antecessor = atual;
            atual = atual->getProximo();
            cont++;
        }

        if (atual == nullptr) {
            return -1;
        }

        dado = atual->getConteudo();
        antecessor->setProximo(atual->getProximo());
        
        delete atual;
        tamanho--;

        return dado;
    }
}

void ListaEncadeada::imprimirLista() {
    No* atual = cabeca;
    while (atual != nullptr) {
        cout << atual->getConteudo() << " ";
        atual = atual->getProximo();
    }
    cout << endl;
}
