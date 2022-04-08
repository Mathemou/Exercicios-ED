#include "aluno.h"
#include "abb.h"

struct arvore {
  Aluno * aluno;
  Arvore * arvore_esquerda;
  Arvore * arvore_direita;
};

Arvore * abbCria(void){
  return NULL;
}

void abbImprime(Arvore * arvore){
  if(arvore!=NULL){
    abbImprime(arvore->arvore_esquerda);
    ImprimeAluno(arvore->aluno);
    abbImprime(arvore->arvore_direita);
  }
}

Arvore * abbBusca(Arvore * arvore, int chave){
  if(arvore==NULL){
    return NULL;
  } else if (RetornaMat(arvore->aluno) > chave){
    return abbBusca(arvore->arvore_esquerda, chave);
  } else if (RetornaMat(arvore->aluno) < chave){
    return abbBusca(arvore->arvore_direita, chave);
  } else {
    return arvore;
  }
  
}

Arvore * abbInsere (Arvore * arvore, Aluno * aluno){
  if (arvore==NULL){
    arvore = (Arvore *) malloc (sizeof(Arvore));
    arvore->aluno = aluno;
    arvore->arvore_esquerda = arvore->arvore_direita = NULL;
  }
  else if (RetornaMat(aluno) < RetornaMat(arvore->aluno)){
    arvore->arvore_esquerda = abbInsere(arvore->arvore_esquerda, aluno);
  } else if (RetornaMat(aluno) > RetornaMat(arvore->aluno)){
    arvore->arvore_direita = abbInsere(arvore->arvore_direita, aluno);
  }
  return arvore;
}

Arvore * abbRetira (Arvore * arvore, int valor){
  if (arvore==NULL){
    return NULL;
  }
  else if (RetornaMat(arvore->aluno) > valor){
    arvore->arvore_esquerda = abbRetira(arvore->arvore_esquerda, valor);
  } else if (RetornaMat(arvore->aluno) < valor){
    arvore->arvore_direita = abbRetira(arvore->arvore_direita, valor);
  } else if (RetornaMat(arvore->aluno)==valor){
    
    if(abbEhFolha(arvore)){
      free(arvore);
      arvore = NULL;
    }

    else if (arvore->arvore_esquerda ==NULL){
      Arvore * t = arvore;
      arvore = arvore->arvore_direita;
      free(arvore);
    }

    else if (arvore->arvore_direita==NULL){
      Arvore * t = arvore;
      arvore = arvore->arvore_esquerda;
      free(arvore);
    }

    else {
      Arvore * f = arvore->arvore_esquerda;
      while (f->arvore_direita != NULL){
        f = f->arvore_direita;
      }
      Aluno * t = arvore->aluno;
      arvore->aluno = f->aluno;
      f->aluno = t;
      arvore->arvore_esquerda = abbRetira(arvore->arvore_esquerda, valor);
    }
  }
  return arvore;
}

Arvore * abbLibera(Arvore * arvore){
  if (!arvore==NULL){
        abbLibera(arvore->arvore_esquerda);
        abbLibera(arvore->arvore_direita);
        free(arvore);
    }
    return NULL;
}

int abbEhFolha (Arvore * arvore){
  if (arvore->arvore_esquerda == NULL && arvore->arvore_direita==NULL){
    return 1;
  } else {
    return 0;
  }
}

//valgrind --leak-check=full --show-leak-kinds=all ./main