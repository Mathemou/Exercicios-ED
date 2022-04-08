#include <stdio.h>
#include "aluno.h"
#include "arvore.h"

int main(){
    //Cria os alunos
    Aluno * matheus = InicAluno(2020102131, "Matheus", 7);
    Aluno * daniela = InicAluno(2020102132, "Daniela", 10);
    Aluno * monica = InicAluno(2020102133, "Monica", 10);
    Aluno * eugenio = InicAluno(2020102134, "Eugenio", 0);
    Aluno * alvarininho = InicAluno(2020102135, "Alvarininho", 5);
    Aluno * matheus2 = InicAluno(2020102136, "Matheus", 4);
    Aluno * matheus3 = InicAluno(2020102137, "Matheus", 10);

    //Cria a árvore completa
    Arv * arv = arv_cria(matheus,
                    arv_cria(daniela, 
                        arv_cria(eugenio, arv_criaVazia(), arv_criaVazia()),
                        arv_cria(alvarininho, arv_criaVazia(), arv_criaVazia())),
                    arv_cria(monica, 
                        arv_cria(matheus3, arv_criaVazia(), arv_criaVazia()), 
                        arv_cria(matheus2, arv_criaVazia(), arv_criaVazia()))
    );

    //Cria árvore por pedaços
        //Cria folhas
        /*Arv * folha_monica = arv_cria(monica, arv_criaVazia(), arv_criaVazia());
        Arv * folha_eugenio = arv_criaVazia(eugenio, arv_criaVazia(), arv_criaVazia());
        Arv * folha_alvarininho = arv_cria(alvarininho, arv_criaVazia(), arv_criaVazia());
        //Cria nós
        Arv * no_daniela = arv_cria(daniela, folha_eugenio, folha_alvarininho);
        Arv * raiz_matheus = arv_cria(matheus, no_daniela, folha_monica);*/

    //Imprime a árvore
    printf("Arvóre em notação textual:\n");
    arv_imprime(arv);
    printf("\n\nQuantidade de folhas: %d", folhas(arv));
    printf("\n\nAparições de Matheus: %d", ocorrencias(arv, "Matheus"));
    
    printf("\n\nAltura: %d", arv_altura(arv));
    arv_libera(arv);
    DestroiAluno(matheus);
    DestroiAluno(daniela);
    DestroiAluno(monica);
    DestroiAluno(alvarininho);
    DestroiAluno(eugenio);
    DestroiAluno(matheus2);
    DestroiAluno(matheus3);
    return 0;
}