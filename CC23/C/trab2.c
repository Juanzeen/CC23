#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int* createArr(int el){ //define o vetor, o asterisco depois do tipo da função retorna um ponteiro.  
    int *arr, j;
    arr = (int*)malloc(el*sizeof(int)); //separa um espaço na memória para que o vetor seja criado
    if(!arr){
        printf("Erro no malloc!!"); 
        exit(1);
    }

    srand(time(NULL));

    for(j=0; j<el; j++){
        arr[j] = rand()%100;
    }

    return arr;
}

void showArr(int el, int *arr){//exibe o vetor
    int j = 0;
    printf("\nArray: \n");
    for(j; j<el; j++){
        printf("%d\t", arr[j]);
    }
}

int centerPos(int initialP, int finalP, int *arr){
    int startP, center, temp;

    startP = initialP; //posição de começo recebe posição inicial
    center = arr[initialP]; //pivo recebe o primeiro elemento do vetor
    initialP++;

    while(initialP<=finalP){
        while(center>=arr[initialP]&&initialP<=finalP)
                initialP++; //sempre que o pivo for maior que algum elemento da parte esquerda e a posição inicial menor que a 
                            //final, a posição inicial recebe +1

        while(finalP>=0&&center<arr[finalP])
            finalP--; //sempre que a posição final for maior ou igual a 0 e o pivo menor que os numeros da direita
                        //posição final decrementa 1

        if(initialP<finalP){ //se a posição inicial for menor que a final
                temp = arr[initialP]; //temp recebe elemento da parte esquerda
                arr[initialP] = arr[finalP]; //elemento da esquerda recebe elemento da direita
                arr[finalP] = temp; //elemento da direita recebe elemento da esquerda
                finalP--;
                initialP++;
        }        
    }
    arr[startP] = arr[finalP];
    arr[finalP] = center;


    return finalP;
}

int catchCenter(int *arr){
    return arr[0]; // o pivo sempre é o primeiro elemento da array
}

void organize(int initialP, int finalP, int *arr){
    int correctP, el = finalP +1;

    if(initialP<finalP){
        correctP = centerPos(initialP, finalP, arr);
        showArr(el,arr);
        organize(initialP, correctP-1, arr); //organiza os elementos antes do pivo
        //showArr(correctP-1, arr); mostrando apenas os menores
        organize(correctP+1, finalP, arr); //organiza os elementos depois do pivo
        //showArr(correctP+1, arr) mostrando apenas os maiores
    }
}


 int main (void){
    int el, *arr, positionF, center; //pivo é o elemento que deve ser colocado na posição certa
    printf("Input the elements of the array: ");
    scanf("%d", &el);
    arr = createArr(el);
    center = catchCenter(arr);
    showArr(el,arr);
    positionF = centerPos(0, el-1, arr);
    printf("\n\t---------------\nThe center is %d and is in the positition: %d\n", center, positionF);
    organize(0, el-1, arr);
    showArr(el, arr);
    printf("\n\t----------------\nOrganized array.\n");
    free(arr);
    return 0;
 }