#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.h"

void AbreArquivo(FILE **arq,char diretorio[],char modo[10]){
    *arq=fopen(diretorio,modo);
    if(arq==NULL){
        printf("Falha ao abrir o arquivo\n");
    }else{
        printf("Arquivo aberto com sucesso\n");
    }
}
void FechaArquivo(FILE **arq){
    fclose(*arq);
    printf("Arquivo fechado\n");
}
void ImprimeArquivo(FILE **arq){
    char linha[11];
    while(fgets(linha,sizeof(linha),*arq)!=NULL){
        printf("%s",linha);
    }
    printf("\n");
}
void LeituraArquivo(FILE **arq, Tabuleiro *T){
    char c;
    int linha=1,
        coluna=1;
    do{
        c=fgetc(*arq);
        if(c!=10 && c!=32){
            SetElemento(T,linha,coluna,c);
            coluna++;
            if(coluna>T->n){
                linha++;
                coluna=1;
            }
        }
    }while(c!=EOF);
}
/* FUNÇÕES JOGO DA VELHA */
void BotVelha(Tabuleiro *T, int i, int j){
    if(TestaSeq(T,i,j)){
        exit(0);
    }else if(duasLinhas(T)){
        exit(0);
    }else if(preencheQuina(T,i,j)){
        exit(0);
    }else{
        Jogada(T);
    }
}
int Jogada(Tabuleiro *T){
    int i,j;
    for(i=0;T->n;i++){
        for(j=0;T->n;j++){
            if(GetElemento(*T,i,j)=='_'){
                SetElemento(T,i,j,'O');
                exit(1);
            }
        }
    }
    return 0;
}
int preencheQuina(Tabuleiro *T, int i, int j){
    if((i==0 && j==0) && GetElemento(*T,i,j)=='X'){
        SetElemento(T,2,2);
        return 1;
    }else if((i==0 && j==2) && GetElemento(*T,i,j)=='X'){
        SetElemento(T,2,0);
        return 1;
    }else if((i==2 && j==0) && GetElemento(*T,i,j)=='X'){
        SetElemento(T,0,2);
        return 1;
    }else if((i==2 && j==2) && GetElemento(*T,i,j)=='X'){
        SetElemento(T,0,0);
        return 1;
    }
    return 0;
}
int duasLinhas(Tabuleiro *T){
    if(GetElemento(*T,0,0)=='O' && GetElemento(*T,0,2)=='O'){
        if(GetElemento(*T,2,0)=='_'){
            SetElemento(T,2,0,'O');
            return 1;
        }else if(GetElemento(*T,2,2)=='_'){
            SetElemento(T,2,2,'O');
            return 1;
        }
    }else if(GetElemento(*T,0,0)=='O' && GetElemento(*T,2,0)=='O'){
        if(GetElemento(*T,0,2)=='_'){
            SetElemento(T,0,2,'O');
            return 1;
        }else if(GetElemento(*T,2,2)=='_'){
            SetElemento(T,2,2,'O');
            return 1;
        }
    }else if(GetElemento(*T,2,0)=='O' && GetElemento(*T,2,2)=='O'){
        if(GetElemento(*T,0,2)=='_'){
            SetElemento(T,0,2,'O');
            return 1;
        }else if(GetElemento(*T,0,0)=='_'){
            SetElemento(T,0,0,'O');
            return 1;
        }
    }else if(GetElemento(*T,0,2)=='O' && GetElemento(*T,2,2)=='O'){
        if(GetElemento(*T,0,0)=='_'){
            SetElemento(T,0,0,'O');
            return 1;
        }else if(GetElemento(*T,0,0)=='_'){
            SetElemento(T,2,0,'O');
            return 1;
        }
    }
    return 0;
}

int TestaSeq(Tabuleiro *T,int i,int j){
    //CANTO SUPERIOR ESQUERDO
    if(i==0 && j==0){
        if((GetElemento(*T,1,0)==GetElemento(*T,i,j)) && GetElemento(*T,2,0)=='_'){
            SetElemento(T,2,0,'O');
            return 1;
        }else if((GetElemento(*T,0,1)==GetElemento(*T,i,j)) && GetElemento(*T,0,2)=='_'){
            SetElemento(T,0,2,'O');
            return 1;
        }else if((GetElemento(*T,1,1)==GetElemento(*T,i,j)) && GetElemento(*T,2,2)=='_'){
            SetElemento(T,2,2,'O');
            return 1;
        }
    //CANTO SUPERIOR DIREITO
    }else if(i==0 && j==2){
        if((GetElemento(*T,0,1)==GetElemento(*T,i,j)) && GetElemento(*T,0,0)=='_'){
            SetElemento(T,0,0,'O');
            return 1;
        }else if((GetElemento(*T,1,2)==GetElemento(*T,i,j)) && GetElemento(*T,2,2)=='_'){
            SetElemento(T,2,2,'O');
            return 1;
        }else if((GetElemento(*T,1,1)==GetElemento(*T,i,j)) && GetElemento(*T,2,0)=='_'){
            SetElemento(T,2,0,'O');
            return 1;
        }
    //CANTO INFERIOR ESQUERDO
    }else if(i==2 && j==0){
        if((GetElemento(*T,1,0)==GetElemento(*T,i,j)) && GetElemento(*T,0,0)=='_'){
            SetElemento(T,0,0,'O');
            return 1;
        }else if((GetElemento(*T,2,1)==GetElemento(*T,i,j)) && GetElemento(*T,2,2)=='_'){
            SetElemento(T,2,2,'O');
            return 1;
        }else if((GetElemento(*T,1,1)==GetElemento(*T,j,i)) && GetElemento(*T,0,2)=='_'){
            SetElemento(T,0,2,'O');
            return 1;
        }
    //CANTO INFERIOR DIREITO
    }else if(i==2 && j==2){
        if((GetElemento(*T,2,1)==GetElemento(*T,i,j)) && GetElemento(*T,2,0)=='_'){
            SetElemento(T,2,0,'O');
            return 1;
        }else if((GetElemento(*T,1,2)==GetElemento(*T,i,j)) && GetElemento(*T,0,2)=='_'){
            SetElemento(T,0,2,'O');
            return 1;
        }else if((GetElemento(*T,1,1)==GetElemento(*T,i,j)) && GetElemento(*T,0,0)=='_'){
            SetElemento(T,0,0,'O');
            return 1;
        }
    }
    return 0;
}
/*----------------------*/


int main(int argc, char *argv[]){
    Tabuleiro tab;
    FILE *arquivo;
    int controle=0;
    int i,j;
    SetTamanho(&tab,3);
    if(argc>=3){
        AbreArquivo(&arquivo,argv[2],"r");
        LeituraArquivo(&arquivo,&tab);
        FechaArquivo(&arquivo);
    }else{
        MarcaTodos(&tab,'_');
    }
    Imprime(tab);
    do{
        scanf("%d %d",&i,&j);
        if(i>=tab.n || j>=tab.n){
            printf("jogada inválida\n");
        }else{
            SetElemento(&tab,i,j,'X');
        }
    }while(controle!=1);
    return 0;
}
