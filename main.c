#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "matriz.h"
#include <math.h>

int main(){

    int op;
    bool acao = true;
    int linhas, colunas, i, j, valor;

    while(acao){
        printf("Escolha uma opcao:\n 1 - Inicializar a matriz\n 2 - Inserir valores na matriz\n 3 - Consultar valor na matriz\n 4 - Buscar endereco de valor\n 5 - Imprimir vizinhos\n 6 - Sair\n");
        scanf("%d", &op);

        switch(op){

        case 1:
            printf("Insira as linhas e colunas da matriz: ");
            scanf("%d", &linhas);
            scanf("%d", &colunas);

            Matriz* mat = cria_matriz(linhas,colunas);
            break;

        case 2:
            for( i=0; i<mat->linhas; i++){
                for( j=0; j<mat->colunas; j++){
                    insere_valor(mat, i, j, (rand()%100));
                }
            }
            break;

        case 3:

            printf("Insira uma posicao a ser consultada: ");
            scanf("%d  %d", &linhas, &colunas);

            no* aux = consulta_valor(mat, linhas, colunas);

            printf("O valor na posicao [%d][%d] eh: %d\n",linhas, colunas, aux->conteudo);
            break;

        case 4:

            printf("Insira um valor a ser consultada a posicao.");
            scanf("%d", &valor);

            no* aux_1 = busca_valor(mat,valor);
            printf("O endereco de memoria do valor %d eh: %d\n", valor, aux_1);
            break;

        case 5:

            printf("Insira uma posicao para imprimir os vizinhos\n");
            scanf("%d  %d", &linhas, &colunas);

            imprime_vizinho(mat, linhas, colunas);
            break;

        default:
            acao = false;
            libera_matriz(mat);

        }
    }
    return 1;
}
