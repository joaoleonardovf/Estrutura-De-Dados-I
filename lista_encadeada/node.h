#pragma once

class No {
private:
    int conteudo;
    No* proximo;

public:
    No() : conteudo(0), proximo(nullptr) {}

    //Construtor parametrizado
    No(int valor) : conteudo(valor), proximo(nullptr) {}

    int getConteudo() const {
        return conteudo;
    }

    void setConteudo(int valor) {
        conteudo = valor;
    }

    No* getProximo() const {
        return proximo;
    }

    void setProximo(No* prox) {
        proximo = prox;
    }
};
