#pragma once 

class FilaSeq {
    private: 
        int dados[100];
        int inicio;
        int fim;
        int tamMax;
        int nElementos;

    public:
        FilaSeq();

        bool vazia(); 
        bool cheia();
        int tamanho();
        int primeiroElem();
        bool insereFim(int valor);
        int removeInicio();
        void imprimirFila();
};