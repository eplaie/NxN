#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int N, VALOR = 0, i = 0, j = 0;
	srand(time(NULL));
	
    printf("\n|================== Menu ==================|\n");
	printf("Informe N: ");
	scanf("%d", &N);

	int m[N][N];
	
	for(i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			m[i][j] = rand()% 99;
		}
	}
	printf("\nMatriz:\n");
	for(i = 0; i < N; i++){
		printf("%d -> \t", i);
		for( j = 0; j < N; j++){
			printf("[%2d]\t", m[i][j]);
		}
		printf("\n");
	}
	i = j= 0;
	VALOR += m[0][0];
	m[0][0] = -1;
	
	while(i < N){
		while(j < N){
			if(i == N-1){
				if(m[i][j] >= 0){
					VALOR += m[i][j];
					m[i][j] = -1;
				}
				j++;
			}else if(j == 0){
				
				if(m[i+1][j] >= m[i][j+1]){
					i++;
					VALOR += m[i][j];
					m[i][j] = -1;
				}else{
					j++;
					VALOR += m[i][j];
					m[i][j] = -1;
				}
			}else if(j == N-1){
				 
				if(m[i+1][j] >= m[i][j-1]){
					i++;
					VALOR += m[i][j];
					m[i][j] = -1;
				}else{
					j--;
					VALOR += m[i][j];
					m[i][j] = -1;
				}	
			}else{
				if(m[i+1][j] >= m[i][j+1] && m[i+1][j] >= m[i][j-1]){
					i++;
					VALOR += m[i][j];
					m[i][j] = -1;
				}else if(m[i][j+1] >= m[i+1][j] && m[i][j+1] >= m[i][j-1]){
					j++;
					VALOR += m[i][j];
					m[i][j] = -1;
				}else if(m[i][j-1] >= m[i+1][j] && m[i][j-1] >= m[i][j+1]){
					j--;
					VALOR += m[i][j];
					m[i][j] = -1;
				}
			}
		}
		i++;
	}
	printf("\nCaminho realizado:\n");
	for(i = 0; i < N; i++){
		printf("%d -> \t", i);
		for( j = 0; j < N; j++){
			printf("[%2d]\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n Valor: %d\n",VALOR);
	printf("\n\n");
	return 0;
}
