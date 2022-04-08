#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "aluno.h"

struct arv {
    Aluno * aluno;
    Arv * esq;
    Arv * dir;
};

Arv * arv_criaVazia(){
    return NULL;
}

Arv* arv_cria (Aluno * aluno, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->aluno = aluno;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv * arv_libera (Arv * arv){
    if (!arv_vazia(arv)){
        arv_libera(arv->esq);
        arv_libera(arv->dir);
        free(arv);
    }
    return NULL;
}

int arv_vazia (Arv * arv){
    return arv==NULL;
}

int arv_pertence (Arv * arv,char * chave){
    if (arv_vazia(arv)){
        return 0;
    } else {
        return !strcmp(RetornaNome(arv->aluno),chave) ||
        arv_pertence(arv->esq, chave) ||
        arv_pertence(arv->dir, chave);
        //Dá pra fazer alinhando os if's também
    }
}

void arv_imprime (Arv* a){
    printf("<");
    if (!arv_vazia(a)){
    printf("%s", RetornaNome(a->aluno)); 
    arv_imprime(a->esq); 
    arv_imprime(a->dir);
    printf(">");
}
}

static int max2 (int a, int b){
    return (a>b) ? a : b;
}

int arv_altura (Arv * arv){
    if (arv_vazia(arv)){
        return -1;
    } else {
        return 1 + max2(arv_altura (arv->esq), arv_altura(arv->dir));
    }
}

int folhas (Arv * arv){
    if (arv_vazia(arv->esq)&&arv_vazia(arv->dir)){
        return 1;
    } else if (!arv_vazia(arv->esq)&&arv_vazia(arv->dir)){
        return folhas(arv->esq);
    } else if (arv_vazia(arv->esq)&&!arv_vazia(arv->dir)){
        return folhas(arv->dir);
    }
    return folhas(arv->esq) + folhas(arv->dir);
}

int ocorrencias (Arv * arv, char * nome){
    if (arv_vazia(arv)){
        return 0;
        }
        if (!strcmp(nome, RetornaNome(arv->aluno))){
            return (1 + ocorrencias(arv->esq, nome) + ocorrencias(arv->dir, nome));
        }
        return (ocorrencias(arv->esq, nome) + ocorrencias(arv->dir, nome));
    
}