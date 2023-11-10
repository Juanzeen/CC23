#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Element {
    int frequency;
    char character;
}stElement;

typedef struct Array {
    int elQtt;
    stElement *arr;
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
}

void showArr(stArray *arrP){
    for(int i = 0; i< arrP->elQtt; i++){
        printf("%c \t %d\n",arrP->arr[i].character, arrP->arr[i].frequency);
    }
}

int main (void){
    FILE *arch;
    stArray array;
    arch = fopen("textoExemplo.txt", "r"); // r -> read, w -> write e rw -> read/write

    
    if(!arch){
        printf("Error on the txt archive.\n");
        exit(0);
    }

    fillArr(arch, &array);
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