#include <stdio.h>
#include <stdlib.h>
#include "TF.H"
#include <math.h>
#include <string.h>

pNodoA* cria_arvore(void)
{
    return NULL;
}

pNodoA* InsereArvore(pNodoA *a, char palavra[], char lema[])
{
    if (a == NULL)
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        strcpy(a->palavra, palavra) ;
        strcpy(a->lema, lema) ;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (strcmp(a->palavra, palavra))
        a->esq = InsereArvore(a->esq,palavra, lema);
    else
        a->dir = InsereArvore(a->dir,palavra, lema);
    return a;
}


void preFixado(pNodoA *a)
{
    if (a!= NULL)
    {
        printf("Palavra: %s Lema: %s\n",a->palavra, a->lema);

        preFixado(a->esq);
        preFixado(a->dir);
    }
}

int Altura (pNodoA *a)
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
        return 0;
    else
    {
        Alt_Esq = Altura (a->esq);
        Alt_Dir = Altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}

int FatorNodo(pNodoA *a)
{
    return (Altura(a->esq) - Altura(a->dir));
}

int MaiorFator(pNodoA *a, int contador)
{
    if (a!= NULL)
    {
        if(abs(FatorNodo(a))>contador)
            contador = abs(FatorNodo(a));

        MaiorFator(a->esq, contador);
        MaiorFator(a->dir, contador);
    }
    else if(a == NULL)
    return contador;
}


pNodoA* OrdenaDic (char *argv[], pNodoA* a)
{
    char linha[1000];
    char separador[]= {" ,.&*%\?!;/'@\"$#=><()][}{:\n\t"};
    FILE *dicionario;
    char *palavra, *lema;

    dicionario = fopen (argv[1], "r"); // abre o arquivo para leitura -- argv[1] é o primeiro parâmetro após o nome do arquivo.
    if (dicionario == NULL) //se não conseguiu abrir o arquivo
    {
        printf ("Erro ao abrir o arquivo %s", argv[1]);
        return 1;
    }
    else // arquivo de entrada OK
    {
        while (fgets(linha,1000,dicionario)){
                palavra = strtok (linha, separador); //considera qquer caractere não alfabético como separador
                lema = strtok (NULL, separador);
                a=InsereArvore(a ,palavra, lema);
        }
    }

    return a;
}
