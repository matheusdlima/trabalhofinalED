struct TNodoA{
 char palavra[20];
 char lema[20];
 struct TNodoA *esq;
 struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;


pNodoA* cria_arvore(void);
pNodoA* InsereArvore(pNodoA *a, char palavra[], char lema[]);
int Altura (pNodoA *a);
int FatorNodo(pNodoA *a);
int MaiorFator(pNodoA *a, int contador);
pNodoA* OrdenaDic (char *argv[], pNodoA* a);
