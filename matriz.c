#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz* cria_matriz(int lin, int col){

    // Cria a cabeca da matriz (a que apontara para a posicao 0,0)
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    mat->linhas = lin;
    mat->colunas = col;
    mat->cabeca = NULL;

    no** elem = (no**)malloc(lin * sizeof(no*));

    // Criar nos
    for(int i = 0; i < lin; i++){

        elem[i] = (no*)malloc(col * sizeof(no));

        for(int j = 0; j < col; j++){
            elem[i][j].conteudo = 0;
            elem[i][j].baixo = NULL;
            elem[i][j].cima = NULL;
            elem[i][j].direita = NULL;
            elem[i][j].esquerda = NULL;
        }
    }

    // Conecta os nos

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){

            if(i>0){
                elem[i][j].cima = &elem[i-1][j];
                elem[i-1][j].baixo = &elem[i][j];
            }

            if(j>0){
                elem[i][j].esquerda = &elem[i][j - 1];
                elem[i][j - 1].direita = &elem[i][j];
            }

        }
    }

    mat->cabeca = &elem[0][0];

    free(elem);
    return mat;
}

int libera_matriz(Matriz* mat){

    if(mat == NULL)
        return 0;

    no* aux = mat->cabeca;

    /*
    Vai passando o proximo no para o o prox e liberando
    os nos que foi passado para o prox
    */

    while(aux != NULL){
        no* prox = aux->direita;
        free(aux);
        aux = prox;
    }

    free(mat);
    return 1;
}

int insere_valor(Matriz* mat, int linha, int coluna, int n){

    if(mat == NULL || linha >= mat->linhas || coluna >= mat->colunas || linha < 0 || coluna < 0)
        return 0;

    no* aux = mat->cabeca;

    // Desce ate a linha necessaria
    for(int i = 0; i < linha; i++)
        aux = aux->baixo;

    // Navega ate a coluna necessaria
    for(int j = 0; j < coluna; j++)
        aux = aux->direita;

    // passa o valor para o no
    aux->conteudo = n;
    return 1;

}


no* consulta_valor(Matriz* mat, int linha, int coluna){

    if(mat == NULL || linha >= mat->linhas || coluna >= mat->colunas || linha < 0 || coluna < 0)
        return 0;

    no* aux = mat->cabeca;

    // Desce ate a linha necessaria
    for(int i = 0; i < linha; i++)
        aux = aux->baixo;

    // Navega ate a coluna necessaria
    for(int j = 0; j < coluna; j++)
        aux = aux->direita;

    // Retorna o no inteiro
    return aux;
}

no* busca_valor(Matriz* mat, int valor){

    if(mat == NULL){
        printf("Por favor inicialize a matriz primeiro.");
        return NULL;
    }

    no* aux2 = mat->cabeca;

    no* aux = mat->cabeca;

    while(aux != NULL){

        if(aux->conteudo == valor)
            return aux;

        if(aux->direita != NULL){
            aux = aux->direita;

        } else {
            aux = aux2->baixo;
            aux2 = aux2->baixo;

        }
    }

    return NULL;
}


void imprime_vizinho(Matriz* mat, int linha, int coluna){

    if(mat == NULL || linha >= mat->linhas || coluna >= mat->colunas || linha < 0 || coluna < 0){
        printf("Verifique se a matriz esta inicializada e se o numero de linhas e colunas nao passa os limites da matriz.");
        return 0;
    }

    no* aux = consulta_valor(mat,linha,coluna);

    if(aux == NULL){
        printf("Nao encontrado\n");
        return 0;
    }


    // Se for o canto superior esquerdo da matriz
    if(linha == 0 && coluna == 0){
        printf("Vizinho da direita: %d\n", aux->direita->conteudo);
        printf("Vizinho de baixo: %d\n", aux->baixo->conteudo);
    }

    // Se for o canto superior direito da matriz
    else if(linha == 0 && coluna == mat->colunas-1){
        printf("Vizinho de baixo: %d\n", aux->baixo->conteudo);
        printf("Vizinho de esquerda: %d\n", aux->esquerda->conteudo);
    }

    // Se for o canto inferior esquerdo da matriz
    else if(linha == mat->linhas-1 && coluna == 0){
        printf("Vizinho de cima: %d\n", aux->cima->conteudo);
        printf("Vizinho da direita: %d\n", aux->direita->conteudo);
    }

    // Se for o canto inferior direito da matriz
    else if(linha == mat->linhas-1 && coluna == mat->colunas-1){
        printf("Vizinho de cima: %d\n", aux->cima->conteudo);
        printf("Vizinho de esquerda: %d\n", aux->esquerda->conteudo);
    }


    // Se for a primeira linha, mas nao for nenhum canto
    else if(linha == 0 && coluna < mat->colunas){
        printf("Vizinho da direita: %d\n", aux->direita->conteudo);
        printf("Vizinho de baixo: %d\n", aux->baixo->conteudo);
        printf("Vizinho de esquerda: %d\n", aux->esquerda->conteudo);
    }

    // Se for a ultima linha, mas nao for nenhum canto
    else if(linha == mat->linhas-1 && coluna < mat->colunas){
        printf("Vizinho de cima: %d\n", aux->cima->conteudo);
        printf("Vizinho da direita: %d\n", aux->direita->conteudo);
        printf("Vizinho de esquerda: %d\n", aux->esquerda->conteudo);
    }

    // Se for a primeira coluna, mas nao for canto
    else if(linha < mat->linhas && coluna == 0){
        printf("Vizinho da direita: %d\n", aux->direita->conteudo);
        printf("Vizinho de baixo: %d\n", aux->baixo->conteudo);
        printf("Vizinho de cima: %d\n", aux->cima->conteudo);
    }

    // Se for a ultima coluna, mas nao for canto
    else if(linha < mat->linhas && coluna == mat->colunas-1){
        printf("Vizinho de cima: %d\n", aux->cima->conteudo);
        printf("Vizinho de baixo: %d\n", aux->baixo->conteudo);
        printf("Vizinho de esquerda: %d\n", aux->esquerda->conteudo);
    }

    // Se for qualquer outro caso (meio da matriz)
    else{
        printf("Vizinho de cima: %d\n", aux->cima->conteudo);
        printf("Vizinho da direita: %d\n", aux->direita->conteudo);
        printf("Vizinho de baixo: %d\n", aux->baixo->conteudo);
        printf("Vizinho de esquerda: %d\n", aux->esquerda->conteudo);
        printf("Valor do elemento: %d\n", aux->conteudo);
    }

}

void imprime_matriz(Matriz* mat){

    /*
    aux comeca na posicao 0,0 e enquanto o mesmo nao for nulo
    imprime a linha i da matriz, quando a linha da matriz chega ao final
    ele passa para a primeira coluna da linha de baixo e imprime a linha inteira denovo
    */

    no* aux2 = mat->cabeca;
    no* aux = mat->cabeca;

    while(aux != NULL){
        if(aux->direita != NULL){
            printf("[%d]\t", aux->conteudo);
            aux = aux->direita;
        }
        else{
            printf("[%d]\n", aux->conteudo);
            aux2 = aux2->baixo;
            aux = aux2;
        }
    }
}


int sum_mat(Matriz* mat){

    /*
    Essa funcao passa por toda a matriz somando o conteudo de cada elemento
    e ao final imprime a matriz
    */

    no* aux = mat->cabeca;
    no* aux_2 = mat->cabeca;
    int sum = 0;

    while(aux != NULL){

        if(aux->direita != NULL){

            sum += aux->conteudo;
            aux = aux->direita;

        } else {

            sum += aux->conteudo;
            aux_2 = aux_2->baixo;
            aux = aux_2;

        }
    }

    printf("\nTotal: %d\n",sum);

    return 1;

}
