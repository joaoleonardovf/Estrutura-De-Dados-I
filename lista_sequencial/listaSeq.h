#pragma once

class ListaSequencial {
    private:
        int dados[200];
        int tamAtual;
        int tamMaximo;

    public:
        ListaSequencial();

        bool vazia();
        bool cheia();
        int tamanho();
        int obterElemento(int pos);
        bool modificarElemento(int pos, int dado);
        bool inserir(int pos, int dado);
        int retirar(int pos);
        int posicao(int dado);
        void exibirLista();
};
