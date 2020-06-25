#include <stdio.h>
#include <stdlib.h>

/*Jogo da Vida
**Desenvolvido por Gustavo Bispo**
**2∫Sem/2017**
*/
#define MIN 5
#define MAX 10
// Definindo o numero de geracoes a serem printadas caso o usu·rio nao queira configurar
#define N_GERACOES 3

void AbrirArquivoGeracao(int MUNDO[MAX][MAX], int matriz[MAX][MAX], int tam){

    printf("Lendo arquivo...\n\n");

    int linha, coluna;
    FILE *arq;
    char url[] = "recJogo.txt";
    
    arq = fopen(url, "r");
    if(arq == NULL)
            printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        if((fscanf(arq,"Tamanho: %d\n", &tam)) != EOF){
            printf("Tamanho: %d\n", tam);
        }        

        while( (fscanf(arq,"%d - %d\n", &linha, &coluna)) != EOF){
            MUNDO[linha][coluna] = matriz[linha][coluna] = 1;
            printf("Alguem vivo na posicao -> Linha: %d Coluna: %d\n", linha, coluna);
        }    
    fclose(arq);
}

void SalvarArquivo(int MUNDO[MAX][MAX], int matriz[MAX][MAX], int tam){

    int i = 0, j = 0;

    // Variaveis para auxiliar na cria√ß√£o e grava√ß√£o do arquivo
    char rec[100];  
    FILE *arq;
    int result, contador = 0;
    char url[] = "recJogo.txt";  
    
    arq = fopen(url, "wt");

    if(arq == NULL){
        printf("Problemas na criacao do arquivo\n");
    }
    
	//printf("M: %d", tam);

    printf("\n\nSalvando arquivo...\n");

    sprintf(rec, "Tamanho: %d\n", tam);
    printf("Tamanho: %d\n", tam);
    result = fputs(rec, arq);

    for(i=0; i < tam; i++){
        for(j=0; j< tam; j++){
            if(MUNDO[i][j] == 1){                
                sprintf(rec, "%d - %d\n", i,j);
                printf("[%d][%d]\n", i,j );
                result = fputs(rec,arq);
                contador++;
                
            }
        }       
     }
    fclose(arq);
    printf("Gravacao concluida com sucesso\nSeres Vivos gravados: %d\n", contador); 
}

int main(void) {

int m = MAX, i, j, n=0, num, k, vel=1 ,qtde = N_GERACOES, countGeracao = 2;
int MUNDO[100][100], matriz[100][100];
int count=0;
int tamanho = MAX;

for (i=0; i<m; i++) {
	for (j=0; j<m; j++) {
		MUNDO[i][j] = matriz[i][j] =  0;
	}
}


printf("Se deseja carregar uma geraÁ„o salva digite 0 ou se deseja iniciar um novo jogo digite 1: ");
scanf("%d", &n);
if(n==0){
	AbrirArquivoGeracao(MUNDO,matriz, m);


}else{

//definiÁ„o do tamanho do mundo

printf("Digite a dimensao do mundo do Jogo da Vida, o valor deve estar entre %d e %d: ", MIN, MAX);
scanf("%d", &m);

while(m<MIN|| m>MAX){
	printf("\nA dimensao %d e invalida, digite outra dimensao: \n", m);
	scanf("%d", &m);
}

printf("\n");

for (i=0; i<m; i++) {
	for (j=0; j<m; j++) {
		MUNDO[i][j] = 0;
	}
}

//impress„o do mundo
for(num=0; num<m; num++){
	printf("\t%d", num);
}

printf("\n");

for (i=0; i<m; i++) {
	printf("%d", i);
	for (j=0; j<m; j++) {
		printf("\t-");
	}
	printf("\n");
}

//posiÁ„o dos seres da primeira geraÁ„o

printf("\nDigite a posicao i (linha) do ser da primeira geracao: ");
scanf("%d", &i);

while( i != -1){
	printf("\nDigite a posicao j (coluna) do ser da primeira geracao: ");
	scanf("%d", &j);
	MUNDO[i][j] = 1;
	printf("\nDigite a posicao i (linha) do ser da primeira geracao ou digite -1 para continuar ou digite -2 para limpar as cÈlulas marcadas: ");
	scanf("%d", &i);
	if(i == -2){
		for (i=0; i<m; i++) {
			for (j=0; j<m; j++) {
			MUNDO[i][j] = 0;
			}
		}
		printf("\n\tCelulas limpas");
		printf("\nDigite a posicao i (linha) do ser da primeira geracao: ");
		scanf("%d", &i);	
	}
}
}

printf("\n");

printf("\n\t\tGeracao 1");

printf("\n");

//imprime matriz inicial

for(num=0; num<m; num++){
	printf("\t%d", num);
}

printf("\n");
// mundo com as posicoes dos seres da primeira geracao marcadas pelos usuario!!!


for (i=0; i<m; i++) {
	printf("%d", i);
	for (j=0; j<m; j++) {
		if(MUNDO[i][j] == 0){
		printf("\t ");
		} else{
			printf("\t*");
		}
	}
	printf("\n");
}

printf("Se deseja determinar a quantidade de geracoes que serao simuladas digite 0 ou digite 1 para utilizar as configuracoes pre-definidas: ");
scanf("%d", &k);

if( k == 0){
	printf("\nDigite a quantidade de geracoes a serem simuladas: ");
	scanf("%d", &qtde);
	printf("\nDigite 0 para simular as geracoes lentamente ou digite 1 para simular rapido: ");
	scanf("%d", &vel);

}

for (i=0; i<m; i++) {
		for (j=0; j<m; j++) {
			matriz[i][j] = MUNDO[i][j];
		}
	}

for(k=0; k<qtde; k++){
	for (i=0; i<m; i++) {
    	for (j=0; j<m; j++) {
			count = 0;
        	if(MUNDO[((i-1)+ m)%m][((j-1)+ m)%m] == 1){
            	count++;
        	}
        	if(MUNDO[((i-1)+ m)%m][(j + m)%m] == 1){
        	    count++;
        	}
        	if(MUNDO[((i-1)+ m)%m][((j+1)+ m)%m] == 1){
        	    count++;
        	}
        	if(MUNDO[(i + m)%m][((j-1)+ m)%m] == 1){
        	    count++;
        	}
        	if(MUNDO[(i + m)%m][((j+1)+ m)%m] == 1){
        	    count++;
        	}
        	if(MUNDO[((i+1)+ m)%m][((j-1)+ m)%m] == 1){
        	    count++;
        	}
        	if(MUNDO[((i+1)+ m)%m][(j + m)%m] == 1){
        	    count++;
        	}
        	if(MUNDO[((i+1)+ m)%m][((j+1)+ m)%m] == 1){
            	count++;
        	}
        	if(count>= 4){
				matriz[i][j]=0;
			}
			else if(count == 0 || count == 1){
				matriz[i][j]=0;
			} else if(count == 3){
				matriz[i][j]=1;
			}else if(count == 2 && MUNDO[i][j]==1){
				matriz[i][j]= 1;
			}else if(count == 2 && MUNDO[i][j]==0){
				matriz[i][j]= 0;
			}
    	}
    }

	if(count>= 4){
		matriz[i][j]=0;
	} else if(count == 0 || count == 1){
		matriz[i][j]=0;
		} else if(count == 3){
			matriz[i][j]=1;
			}else if(count == 2 && MUNDO[i][j]==1){
				matriz[i][j]= 1;
				}else if(count == 2 && MUNDO[i][j]==0){
					matriz[i][j]= 0;
	}
	
	for (i=0; i<m; i++) {
		for (j=0; j<m; j++) {
			MUNDO[i][j] = matriz[i][j];
		}
	}
	
	printf("\t\tGeracao %d\n", countGeracao);
	countGeracao++;

		
	for(num=0; num<m; num++){
		printf("\t%d", num);
	}

	printf("\n");

	for (i=0; i<m; i++) {
		printf("%d", i);
		for (j=0; j<m; j++) {

			if(MUNDO[i][j] == 0){
				printf("\t ", MUNDO[i][j]);
			} else{
				printf("\t*", MUNDO[i][j]);
			}

		}
		printf("\n");
		}
		sleep(1);
	if(vel==0){
		sleep(4);
	}
}

printf("Se deseja salvar a geraÁ„o digite 0 ou se deseja sair sem salvar digite 1: ");
scanf("%d", &n);

if(n==0){
	SalvarArquivo(MUNDO, matriz, m);
}

return 0;
}
