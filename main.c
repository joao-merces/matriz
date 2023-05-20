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
        printf("Escolha uma opcao:");
        printf("\n1 - Criar matriz");
        printf("\n2 - Inserir na matriz");
        printf("\n3 - Consultar valor na matriz");
        printf("\n4 - Buscar endereco de valor");
        printf("\n5 - Imprimir vizinhos");
        printf("\n6 - Imprime matriz");
        printf("\n7 - Somatorio da matriz");
        printf("\n8 - Sair\n");
        scanf("%d", &op);

        switch(op){

        case 1:
            printf("\nInsira as linhas: ");
            scanf("%d", &linhas);
            printf("Insira as colunas: ");
            scanf("%d", &colunas);
            printf("\n");

            Matriz* mat = cria_matriz(linhas,colunas);
            break;

        case 2:
            for( i=0; i<mat->linhas; i++){
                for( j=0; j<mat->colunas; j++){
                    insere_valor(mat, i, j, (rand()%100));
                }
            }

            printf("\nMatriz preenchida\n\n");
            break;

        case 3:

            printf("\nInsira a linha a ser consultada: ");
            scanf("%d", &linhas);
            printf("Insira a coluna a ser consultada: ");
            scanf("%d", &colunas);

            no* aux = consulta_valor(mat, linhas, colunas);

            printf("\nO valor na posicao [%d][%d] eh: %d\n\n",linhas, colunas, aux->conteudo);
            break;

        case 4:

            printf("\nInsira um valor a ser consultada a posicao: ");
            scanf("%d", &valor);

            no* aux_1 = busca_valor(mat,valor);
            printf("\nO endereco de memoria do valor %d eh: %d\n\n", valor, aux_1);
            break;

        case 5:

            printf("\nInsira a linha: ");
            scanf("%d",&linhas);

            printf("Insira a coluna: ");
            scanf("%d",&colunas);
            printf("\n");

            imprime_vizinho(mat, linhas, colunas);
            printf("\n");
            break;

        case 6:
            printf("\n");
            imprime_matriz(mat);
            printf("\n");
            break;

        case 7:
            sum_mat(mat);
            break;

        case 8:
            acao = false;
            libera_matriz(mat);

        default:
            acao = false;
            libera_matriz(mat);

        }
    }
    return 1;
}
