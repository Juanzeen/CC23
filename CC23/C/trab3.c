#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <math.h>

typedef struct sPoint{
        float x, y;
        float angle;
    }stPoint; //colocamos outro nome no final para que nao seja necessario passar struct nome_struct

typedef struct  sArr{
    int elNumbers;
    stPoint *arr;   
    }stArr;

stPoint createPoints(stArr *arrP){//função parar criar os pontos
    stPoint center;
    srand(time(NULL));
    for(int i = 0; i < arrP->elNumbers; i++){
        arrP->arr[i].x =  rand()%100;//sorteia x
        arrP->arr[i].y =  rand()%100;//sorteia y
        center.x +=  arrP->arr[i].x; //centro de x recebe todos os valores de x de cada ponto
        center.y +=  arrP->arr[i].y; //centro de y recebe todos os valores de y de cada ponto
    }

    center.x/= arrP->elNumbers; //os valores dos pontos de x é dividido pelo total de pontos, para ser o centro real
    center.y/= arrP->elNumbers; //mesmo processo de cima para o y
    center.angle = 0.0; //o angulo do centro é 0

    return center; //retorna o centro
}   


void showArr (stArr *arrP){//exibindo o vetor
     for(int i = 0; i< arrP->elNumbers; i++){
        printf("( %.1f\t, %.1f\t, %.2fº)\n", arrP->arr[i].x, arrP->arr[i].y, arrP->arr[i].angle);   
        }
    printf("----------------------\n");
}

void createArrays(stArr *arrP, stPoint center){//criando os vetores a partir do centroide
        for (int i = 0; i<arrP->elNumbers; i++){//todos os pontos virão vetores traçados a partir do centroide
            arrP->arr[i].x -= center.x;
            arrP->arr[i].y -=center.y;
        }
        
}

void calcAngle(stArr *arrP){//calculo do angulo
    float h, cos, arccos;

    for (int i = 0; i< arrP->elNumbers; i++){
        h = sqrt((arrP->arr[i].x * arrP->arr[i].x) + (arrP->arr[i].y * arrP->arr[i].y) ); //pitagoras para obter a hipotenusa
        cos = arrP->arr[i].x/h; //dividimos a hipotenusa pelo cat adj para obter o cos
        arccos =  acos(cos); //usamos o acos para descobrir o angulo que gera esse valor de cos

        if(cos >=0){
            if(arrP->arr[i].y<0){
                arccos = 360 - arccos; //dando o valor ao cateto oposto a partir do cos
            }

            else{

                if(arrP->arr[i].y<0)
                    arccos = 180 + arccos;

                else 
                    arccos = 180 - arccos;
            }
        }

    arrP->arr[i].angle = arccos; //o angulo de cada vetor é o arccos
    
    }
}

int centerPos(int initialP, int finalP, stArr *arrP){//posição certa do segundo trabalho adaptado
    int startP;
    float centerA;
    stPoint centerP, temp;

    startP = initialP; //posição de começo recebe posição inicial
    centerA = arrP->arr[initialP].angle; //pivo recebe o primeiro elemento do vetor
    centerP = arrP->arr[initialP];
    initialP++;

    while(initialP<=finalP){
        while(centerA >= arrP->arr[initialP].angle && initialP <= finalP)
                initialP++; //sempre que o pivo for maior que algum elemento da parte esquerda e a posição inicial menor que a 
                

        while(finalP >= 0 && centerA < arrP->arr[finalP].angle)
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
    arrP->arr[finalP] = centerP;


    return finalP;
}

void organize(int initialP, int finalP, stArr *arrP){ //quicksort do trabalho 2 adaptado
    int correctP;

    if(initialP<finalP){
        correctP = centerPos(initialP, finalP, arrP);
        organize(initialP, correctP-1, arrP); //organiza os elementos antes do pivo
        organize(correctP+1, finalP, arrP); //organiza os elementos depois do pivo
    }
}


float calcArea(stArr *arrP){//calculando a area do poligono
    int j; 
    float sumArea = 0.0f, area;

        for(int i = 0; i <arrP->elNumbers; i++){
            j = (i+1)%(arrP->elNumbers);
            sumArea = abs(((arrP->arr[j].x - arrP->arr[i].x) * (arrP->arr[j].y + arrP->arr[i].y)))/2; //calculo parcial de cada vetor
            area += sumArea; //recebe o somatorio do parcial de cada vetor para retornar a area total
        }
        return area ; 
        }  


int main(void)
{
    int el;
    stArr array;
    stPoint center;
    float totalArea;

    //criando vetor de pontos 
    printf("Input the number of points you want ");
    scanf("%d", &el);
    array.arr = malloc(el*sizeof(stPoint));
    array.elNumbers = el;
    center = createPoints(&array); //ja retorna o centroide
    showArr(&array);

    //criando vetores e angulo
    createArrays(&array, center);
    showArr(&array);
    calcAngle(&array);
    showArr(&array);

    //organizando os vetores com quicksort e calculando área
    organize(0, array.elNumbers-1, &array);
    totalArea = calcArea(&array);
    showArr(&array);
    printf("A área total do polígono foi %.2f\n", totalArea);
    
    return 0;
}
