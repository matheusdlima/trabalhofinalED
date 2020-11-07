#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "TF.H"
#include <math.h>


int main(int argc, char *argv[]) //argc conta o número de parâmetros e argv armazena as strings correspondentes aos parâmentros digitados
{
    setlocale(LC_ALL,""); //para imprimir corretamente na tela os caracteres acentuados

   // clock_t start, end; //para contar o tempo decorrido
    FILE * entrada;
    FILE * saida;

    pNodoA *AVL;

    if (argc!=4)  //o numero de parametros esperado é 3: nome do programa (argv[0]), nome do arq de entrada(argv[1]), nome do arq de saida(argv[2])
    {
        printf ("Número INCORRETO de parâmetros.\n Para chamar o programa digite: exemplo <arq_entrada> <arq_saida>\n");
        return 1;
    }
    else{

        AVL = cria_arvore();
        AVL = OrdenaDic(argv, AVL);

        char lema[20];
char linha[1000];
char *palavra;
char separador[]= {" ,.&*%\?!;/'@\"$#=><()][}{:\n\t"};

            entrada = fopen (argv[2], "r"); // abre o arquivo para saida -- argv[2] é o segundo parâmetro após o nome do arquivo.
            saida = fopen(argv[3], "w");


            //percorre todo o arquivo lendo linha por linha
            while (fgets(linha,1000,entrada))
            {
                palavra = strtok (linha, separador); //considera qquer caractere não alfabético como separador
                while (palavra != NULL)
                {
                    strcpy(lema, palavra);
                    procuraPalavra(AVL, palavra, lema);

                    fprintf(saida,"%s ", lema);

                    palavra = strtok (NULL, separador);
                }
                fprintf(saida,"\n");
            }

            printf("\nArquivo %s gerado com sucesso.\n",argv[3]);

    }
            fclose (entrada); //fecha os arquivos
        fclose (saida);
         //   start = clock(); //inicia a contagem do tempo

/*
            //percorre todo o arquivo lendo linha por linha
            while (fgets(linha,1000,entrada))
            {
                palavra = strtok (linha, separador); //considera qquer caractere não alfabético como separador
                while (palavra != NULL)
                {
                    strcpy(lema, palavra);
                    procuraPalavra(AVL, palavra, lema);

                    fprintf(saida,"%s ", lema);

                    palavra = strtok (NULL, separador);
                }
                fprintf(saida,"\n ");
            }

            printf("\nArquivo %s gerado com sucesso.\n",argv[3]);

         //   end = clock(); // finaliza contagem do tempo
        //    float miliseconds = (float)(end - start) / CLOCKS_PER_SEC * 1000; //calcula o tempo decorrido
          //  printf("Tempo: %.5f ms\n",miliseconds);
        }
        fclose (entrada); //fecha os arquivos
        fclose (saida);
*/
        return 0;

}


