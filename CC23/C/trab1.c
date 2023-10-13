#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillHQ(int hq[10][10]){
int i,j;
srand(time(0));//prepara para que a função rand seja executada sempre partindo de uma "semente" diferente, o que gera valores diferentes sempre que o programa for executado.
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            hq[i][j] = rand()%100;//sorteia os numeros a partir de da semente definida anteriormente
    }
    }

}

void showHQ(int hq[10][10]){//mostra a matriz
int i,j;
    printf("\nHeadquarter:\n");
    
    for(i=0; i<10; i++){
        printf("\n");
            for(j=0; j<10; j++){
                printf("%d ",hq[i][j]);
       }
    }

    printf("\n");
}

void fillArrayT(int t, int arrayT[10],int hq[10][10]){//preenche o vetor
int r,i,j;
    srand(time(0));
    
    for(r=0; r<t; r++) {
        i = rand()%10;
        j = rand()%10;
        arrayT[r] = hq[i][j];
    }

}

void showA(int t, int array[10]) {//mostra o vetor
    
    printf("\nArray:\n");

    for(int i=0; i<t; i++){
        printf("%d\t",array[i]);
}
}

void compareArAndHQ(int t, int array[10], int hq[10][10], int indexHQ[10][10]){//compara os valores da matriz com o vetor dos parametros
    int i,j,r,smallerR,d,lowerD;
      for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            lowerD=300;
            for(r=0;r<t;r++){
                d=abs(hq[i][j]-array[r]);
                    if(lowerD>d){
                        lowerD = d;
                        smallerR = r;
                    }
        }
        indexHQ[i][j]= smallerR;
    }
}

}


void fillAvgArray(int t, int newArrayT[10], int indexHQ[10][10], int randomHQ[10][10]){
	int counter[10], i, j, r;
	for(i = 0; i<t; i++){
		newArrayT[i] = 0;
		counter[i] = 0;
	}
	
	for(i=0; i<10; i++){
		for(j=0;j<10;j++){
			r = indexHQ[i][j];
			newArrayT[r]+=randomHQ[i][j];
			counter[r]+=1;
		}
	}
	
	for(i=0;i<t;i++){
		newArrayT[i]/=(float)counter[i];
	}
}

int calcDistance(int t, int arrayT[10], int newArrayT[10]){//funcao que calcula distancia entre o vetor de parametros e o vetor de medias
int distance = 0;


    for(int i = 0; i<t; i++){
        distance += abs(newArrayT[i] - arrayT[i]);

    }

    return distance;

}

void fillFinalHQ(int t, int array[10], int hqI[10][10], int hqF[10][10]){//faz a matriz final com base na matriz de �ndices, substituindo os valores correspondentes do vetor de parametros
    int i, j, k;
    for(k=0;k<t;k++){
         for(i=0; i<10; i++){
            for(j=0; j<10; j++){
                    if(k==hqI[i][j]){
                        hqF[i][j]=array[k];
                    }
                }
           
		    }
        }
}

void copy(int t, int arrayT[10], int newArrayT[10]){//copia um vetor no outro, nesse caso copia o vetor de medias no vetor de parametros
    int i;

    for(i = 0; i < t; i++){
        arrayT[i] = newArrayT[i];
    }
}

int main(void){
    int randomHQ[10][10], indexHQ[10][10], finalHQ[10][10], t, arrayT[10], error=5, newArrayT[10], d;
    //preenchendo e exibindo matriz aleatoria/entrada
    fillHQ(randomHQ);
    showHQ(randomHQ);
    
    //preenchendo e exibindo vetor de parametros
    printf("\nInput the value of the parameter of the array: ");
    scanf("%d", &t);
    fillArrayT(t,arrayT,randomHQ);
    showA(t, arrayT);

    while(1){
    //exibindo matiz indice
    compareArAndHQ(t,arrayT,randomHQ,indexHQ);
    showHQ(indexHQ);
    // criando vetor de médias 
    fillAvgArray(t,newArrayT,indexHQ,randomHQ);
    showA(t,newArrayT);
    //calcula a distancia do vetor de parametros com o novo vetor de parametros
    d = calcDistance(t, arrayT, newArrayT);

    if(d<error){
        //preenche a matriz de saída caso a distancia seja menor que o erro pré estabelecido
        fillFinalHQ(t,newArrayT,indexHQ, finalHQ);
        break;
    }
    else{
        //copia o vetor novo com as médias no vetor de parametros quando a distancia nao é menor que o erro
        copy(t, arrayT, newArrayT);
    }

}
   
    showHQ(finalHQ);
  

    return 0;
}