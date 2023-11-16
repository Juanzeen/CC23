#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_DEPRECATE

typedef struct Element {
    int frequency;
    char character;
}stElement;

typedef struct Array {
    int elQtt;
    stElement *arr;
    int organized;
} stArray;

void fillArr(FILE *archP, stArray *arrP){
    char charM;
    int j;

    arrP->arr = (stElement*) malloc(256*sizeof(stElement));
    arrP->elQtt = 0;
    
    fscanf(archP,"%c", &charM);
    while(!feof(archP)){
        for(j = arrP->elQtt - 1; j>=0 ;j--){
            if(arrP->arr[j].character == charM)
                break;
        }

        if(j<0){
            arrP->arr[arrP->elQtt].character = charM;
            arrP->arr[arrP->elQtt].frequency  = 1;
            arrP->elQtt +=1;
    }
        else
            arrP->arr[j].frequency += 1;
        
        fscanf(archP, "%c", &charM);
    }
    arrP->organized = 0;
}

void showArr(stArray *arrP){
	int i;

    if(arrP->organized==0){
    	 for(i = 0; i< arrP->elQtt; i++){
        	printf("%c \t %d\n",arrP->arr[i].character, arrP->arr[i].frequency);	
	
        }
    }

    else {
         for(i = arrP->elQtt-1; i>0; i--){
        	printf("%c \t %d\n",arrP->arr[i].character, arrP->arr[i].frequency);
        }
    }	
	
}
    	


int centerPos(int initialP, int finalP, stArray *arrP){//posição certa do segundo trabalho adaptado
    int startP, centerF;
    stElement centerChar, temp;

    startP = initialP; //posição de começo recebe posição inicial
    centerF = arrP->arr[initialP].frequency; //pivo recebe o primeiro elemento do vetor
    centerChar = arrP->arr[initialP];
    initialP++;

    while(initialP<=finalP){
        while(centerF >= arrP->arr[initialP].frequency && initialP <= finalP)
                initialP++; //sempre que o pivo for maior que algum elemento da parte esquerda e a posição inicial menor que a 
                

        while(finalP >= 0 && centerF < arrP->arr[finalP].frequency)
            finalP--; //sempre que a posição final for maior ou igual a 0 e o pivo menor que os numeros da direita
            //posição final decrementa 1

        if(initialP<finalP){ //se a posição inicial for menor que a final
                temp = arrP->arr[initialP]; //temp recebe elemento da parte esquerda
                arrP->arr[initialP] = arrP->arr[finalP]; //elemento da esquerda recebe elemento da direita
                arrP->arr[finalP] = temp; //elemento da direita recebe elemento da esquerda
                finalP--;
                initialP++;
        }        
    }
    arrP->arr[startP] = arrP->arr[finalP];
    arrP->arr[finalP] = centerChar;


    return finalP;
}

void organize(int initialP, int finalP, stArray *arrP){ //quicksort do trabalho 2 adaptado
    int correctP;

    if(initialP<finalP){
        correctP = centerPos(initialP, finalP, arrP);
        organize(initialP, correctP-1, arrP); //organiza os elementos antes do pivo
        organize(correctP+1, finalP, arrP); //organiza os elementos depois do pivo
    }
    
    arrP->organized+=1;
}

int main (void){
    FILE *arch; 
    stArray array;
     

    
    arch = fopen("Texto.txt", "r");// r -> read, w -> write e rw -> read/write ;
    if(!arch){
        printf("Error on the txt archive.\n");
        exit(0);
    }

    fillArr(arch, &array);
    printf("Getting characters: \n\n");
    showArr(&array);
    organize(0, array.elQtt-1,&array);
    printf("\nOrganized:\n\n");
    showArr(&array);
    fclose(arch);

    free(array.arr);

    return 0;
}
    //cada elemento do vetor vai ser um caracter da tabela ASCII
    //tabela ASCII possui 256 bits, logo vamos declarar um vetor que tem 255 posições
    //há diferenciação de letra maiuscula para minuscula
    //a cada vez que passamos uma posição lemos o vetor inteiro novamente a partir da ultima posição ocupada
    //dessa maneira é possível checar se o caracter se repete ou se é um novo caracter
    //quando trabalhamos com arquivo em C é obrigatório primeiro definir o arquivo, para isso usamos o FILE *aqr