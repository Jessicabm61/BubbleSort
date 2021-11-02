#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100 //Define o tamanho da constante MAX

int main(int argc, char *argv[]) {
	
	srand ( time (0)); /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
  com o valor da função time(NULL). Este por sua vez, é calculado
  como sendo o total de segundos passados desde 1 de janeiro de 1970
  até a data atual.
  Desta forma, a cada execução o valor da "semente" será diferente.
  */
	
	int i;
	int v[MAX];
	for (i = 0; i <MAX;i++){
		v[i] = rand ();
	}
	
	for (i = 0; i<MAX; i++) {
		printf ("%d: %d\n", i, v[i]);
	}	
	
	//Ordenação usando o BubbleSort 
	//Números grandes sobem rapidamente
 
	int fez_troca;
	do {
		fez_troca = 0;
		for ( i = 0; i < MAX-1; i++){
			if (v[i] > v[i+1]) { //se o v[i] for menor que o vetor adjacente troca
				int aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				fez_troca = 1; 
			}	
		}
	}while (fez_troca); // enquanto fez_troca for verdadeiro ele vai repetir o do 
	
printf ("---------vetor ordenado\n");
	for (i = 0; i < MAX; i ++){
		printf ("%d\n", v[i]);
	}

//Procura uma chave no vetor ordenado - Busca binária
int chave;
printf ("Digite um valor a ser buscado: \n");
scanf ("%d", &chave);

int achou = 0;
int ini = 0, fim = MAX-1, meio;
int cont = 0;
do {
	cont++;
	meio = (ini + fim) / 2;
	if (v[meio]==chave){
		achou = 1;
	} else {
		if (v[meio]< chave){
			ini = meio + 1;
		}else {
			fim = meio -1;	
		}
	}
} while (!achou && ini <= fim);

if (achou) {
	printf ("Encontrado em %d.\n", meio);	
}else{
	printf ("Nao encontrado!\n");	
	return 0;
}

printf ("Busca executada com %i interacoes.\n", cont);
}
