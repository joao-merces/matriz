#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED


typedef struct Elemento{

    int conteudo;
    struct Elemento* esquerda;
    struct Elemento* direita;
    struct Elemento* cima;
    struct Elemento* baixo;

} no;

typedef struct{

    int linhas;
    int colunas;
    no* cabeca;

} Matriz;

Matriz* cria_matriz(int lin, int col);
int libera_matriz(Matriz* mat);
int insere_valor(Matriz* mat, int linha, int coluna, int n);
no* consulta_valor(Matriz* mat, int linha, int coluna);
no* busca_valor(Matriz* mat, int valor);
void imprime_matriz(Matriz* mat);
int sum_mat(Matriz* mat);
void imprime_vizinho(Matriz* mat, int linha, int coluna);
#endif // MATRIZ_H_INCLUDED
