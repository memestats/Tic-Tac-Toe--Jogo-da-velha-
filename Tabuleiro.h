#ifndef TABULEIRO_H_INCLUDED
#define TABULEIRO_H_INCLUDED
#include <string.h>
typedef struct{
    int n;
    int n_max;
    char matriz[101];
}Tabuleiro;

/*Definir o tamanho do tabuleiro que vai ser utilizado*/
void SetTamanho(Tabuleiro *T, int n){
    memset(T->matriz, 0, sizeof T->matriz);
    T->n_max=n*n;
    T->n=n;
}
/*Colocar um elemento c em uma posição (i,j) do tabuleiro*/
void SetElemento(Tabuleiro *T, int i, int j, char c){
    //FORMULA PADRÃO=> (linha-1)*COLUNAS+(COLUNA-1)
    if((i<=T->n && i>=0) && (j<=T->n && j>=0)){
        T->matriz[((i)*T->n+(j))]=c;
    }
}
/*Recuperar o elemento de uma posição (i,j) o tabuleiro*/
char GetElemento(Tabuleiro T, int i, int j){
    char elemento;
    elemento=T.matriz[((i)*T.n+(j))];
    return elemento;
}
/*Colocar um mesmo elemento c em todas as posições do tabuleiro*/
void MarcaTodos(Tabuleiro *T, char c){
    int i=0;
    int j=0;
    for(i=0;i<T->n;i++){
        for(j=0;j<T->n;j++){
            T->matriz[((i)*T->n+(j))]=c;
        }
    }
}
/*Testar se uma linha i do tabuleiro possui todos os elementos iguais a c, retornando true (1) ou false (0)*/
int TestaLinha(Tabuleiro T, int i, char c){
    int j=0;
    for(j=0;j<T.n;j++){
        if(T.matriz[((i)*T.n+(j))]!=c){
            return 0;
        }
    }
    return 1;
}
/*Testar se uma coluna j do tabuleiro possui todos os elementos iguais a c, retornando true (1) ou false (0)*/
int TestaColuna(Tabuleiro T, int j, char c){
    int i=0;
    for(i=0;i<T.n;i++){
        if(T.matriz[((i)*T.n+(j))]!=c){
            return 0;
        }
    }
    return 1;
}
/*Testar se a diagonal esq-dir possui todos os elementos iguais a c, retornando true (1) ou false (0)*/
int TestaDiagonalED(Tabuleiro T, char c){
    int i=0;
    for(i=0;i<T.n;i++){
        if(T.matriz[((i)*T.n+(i))]!=c){
            return 0;
        }
    }
    return 1;
}
/*Testar se a diagonal dir-esq possui todos os elementos iguais a c, retornando true (1) ou false (0)*/
int TestaDiagonalDE(Tabuleiro T, char c){
    int i=T.n-1;
    int j=0;
    int aux=0;
    for(aux=0;aux<T.n;aux++){
        if(T.matriz[((i)*T.n+(j))]!=c){
            return 0;
        }
        i--;
        j++;
    }
    return 1;
}
/*Testar se uma linha i do tabuleiro possui todos os elementos diferentes, retornando true (1) ou false (0)*/
int TestaDiferente(Tabuleiro T, int i){
    int j;
    int aux;
    char atual, anterior;
    for(aux=0;aux<T.n;aux++){
        atual=T.matriz[((i)*T.n+(aux))];
        for(j=0;j<T.n;j++){
            if(aux!=j){
                if(T.matriz[((i)*T.n+(j))]==atual){
                    return 0;
                }
            }
        }
    }
    return 1;
}
/*Imprimir tabuleiro*/
void Imprime(Tabuleiro T){
    int i;
    int j;
    for(i=0;i<T.n;i++){
        for(j=0;j<T.n;j++){
            printf("%c\t",T.matriz[((i)*T.n+(j))]);
        }
        printf("\n");
    }
}
#endif // TABULEIRO_H_INCLUDED
