#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Estrutura para Grafo usando Matriz de Adjacência
typedef struct {
    int numVertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
} GrafoMatriz;

// Estrutura para Grafo usando Lista de Adjacência
typedef struct Nodo {
    int vertice;
    struct Nodo* prox;
} Nodo;

typedef struct {
    int numVertices;
    Nodo* listaAdj[MAX_VERTICES];
} GrafoListaAdj;

// Funções para Grafo de Matriz de Adjacência
GrafoMatriz* criarGrafoMatriz(int vertices) {
    GrafoMatriz* grafo = (GrafoMatriz*)malloc(sizeof(GrafoMatriz));
    grafo->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            grafo->matriz[i][j] = 0;
    
    return grafo;
}

void adicionarArestaMatriz(GrafoMatriz* grafo, int u, int v) {
    grafo->matriz[u][v] = 1;
    grafo->matriz[v][u] = 1;
}

// Funções para Grafo de Lista de Adjacência
GrafoListaAdj* criarGrafoListaAdj(int vertices) {
    GrafoListaAdj* grafo = (GrafoListaAdj*)malloc(sizeof(GrafoListaAdj));
    grafo->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++)
        grafo->listaAdj[i] = NULL;
    
    return grafo;
}

void adicionarArestaLista(GrafoListaAdj* grafo, int u, int v) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->vertice = v;
    novoNodo->prox = grafo->listaAdj[u];
    grafo->listaAdj[u] = novoNodo;

    novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->vertice = u;
    novoNodo->prox = grafo->listaAdj[v];
    grafo->listaAdj[v] = novoNodo;
}

void imprimirGrafoLista(GrafoListaAdj* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        Nodo* temp = grafo->listaAdj[i];
        printf("Vértice [%d]: ", i);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("NULL\n");
    }
}

// Função de Leitura de Arquivo e Carregamento do Grafo
void lerArquivoGrafo(const char* nomeArquivo, GrafoMatriz* grafoMatriz, GrafoListaAdj* grafoLista) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int u, v, numVertices;
    fscanf(arquivo, "%d", &numVertices);
    
    // Inicializa os grafos
    grafoMatriz->numVertices = numVertices;
    grafoLista->numVertices = numVertices;

    while (fscanf(arquivo, "%d %d", &u, &v) != EOF) {
        adicionarArestaMatriz(grafoMatriz, u, v);
        adicionarArestaLista(grafoLista, u, v);
    }

    fclose(arquivo);
}

// Função para imprimir o caminho do BFS
void imprimirCaminho(int antecessor[], int s, int t) {
    if (t == -1) {
        printf("Não há caminho entre os vértices.\n");
        return;
    }
    if (s == t) {
        printf("%d ", s);
    } else {
        imprimirCaminho(antecessor, s, antecessor[t]);
        printf("%d ", t);
    }
}

// Busca em Largura (BFS) usando Lista de Adjacência
void bfs(GrafoListaAdj* grafo, int s, int t) {
    bool visitado[MAX_VERTICES] = { false };
    int antecessor[MAX_VERTICES];
    for (int i = 0; i < grafo->numVertices; i++) {
        antecessor[i] = -1;
    }

    int fila[MAX_VERTICES];
    int inicio = 0, fim = 0;

    fila[fim++] = s;
    visitado[s] = true;

    while (inicio < fim) {
        int atual = fila[inicio++];

        Nodo* adj = grafo->listaAdj[atual];
        while (adj) {
            int vizinho = adj->vertice;
            if (!visitado[vizinho]) {
                fila[fim++] = vizinho;
                visitado[vizinho] = true;
                antecessor[vizinho] = atual;

                if (vizinho == t) {
                    imprimirCaminho(antecessor, s, t);
                    printf("\n");
                    return;
                }
            }
            adj = adj->prox;
        }
    }

    printf("Não há caminho entre os vértices.\n");
}

// Busca em Profundidade (DFS) iterativa usando Lista de Adjacência
void dfsIterativo(GrafoListaAdj* grafo) {
    bool visitado[MAX_VERTICES] = { false };
    int pilha[MAX_VERTICES];
    int topo = -1;

    for (int s = 0; s < grafo->numVertices; s++) {
        if (!visitado[s]) {
            pilha[++topo] = s;

            while (topo >= 0) {
                int atual = pilha[topo--];

                if (!visitado[atual]) {
                    visitado[atual] = true;
                    printf("%d ", atual);

                    Nodo* adj = grafo->listaAdj[atual];
                    while (adj) {
                        if (!visitado[adj->vertice]) {
                            pilha[++topo] = adj->vertice;
                        }
                        adj = adj->prox;
                    }
                }
            }
            printf("\n");
        }
    }
}

// Função Principal
int main() {
    GrafoMatriz* grafoMatriz = criarGrafoMatriz(MAX_VERTICES);
    GrafoListaAdj* grafoLista = criarGrafoListaAdj(MAX_VERTICES);

    // Lê a instância do arquivo
    lerArquivoGrafo("instancias_grafo/pcv.txt", grafoMatriz, grafoLista);

    // Imprime a matriz de adjacência
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < grafoMatriz->numVertices; i++) {
        for (int j = 0; j < grafoMatriz->numVertices; j++) {
            printf("%d ", grafoMatriz->matriz[i][j]);
        }
        printf("\n");
    }

    // Imprime a lista de adjacência
    printf("\nLista de Adjacência:\n");
    imprimirGrafoLista(grafoLista);

    int inicio, fim;
    printf("\nInsira o primeiro vértice: ");
    scanf("%d", &inicio);
    printf("Insira o segundo vértice: ");
    scanf("%d", &fim);

    // Busca em largura
    printf("\nCaminho BFS de %d a %d: ", inicio, fim);
    bfs(grafoLista, inicio, fim);

    // Busca em profundidade
    printf("\nOrdem DFS iterativa:\n");
    dfsIterativo(grafoLista);

    return 0;
}