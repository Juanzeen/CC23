#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct sPoint{
        int x, y ;
        float angle;
    }stPoint; //colocamos outro nome no final para que nao seja necessario passar struct nome_struct

typedef struct  sArr{
    int elNumbers;
    stPoint *arr;   
    }stArr;

    


 /*float calcArea(stArr *array){
    int angle, angle1, j; 
        float a = 0.0;
        for(int i = 0; i <array->n; i++){
            j = (i+1)%(array->n);
            angle1 = ((array->arr[j].x - array->arr[i].x) * (array->arr[j].y + array->arr[i]))/2;
            angle +=angle1;
        }
        return (angle); 
        }  */ 

void createPoints(stArr *arrP){
    srand(time(NULL));
    for(int i = 0; i < arrP->elNumbers; i++){
        arrP->arr[i].x =  rand()%100;
        arrP->arr[i].y =  rand()%100;
    }
}   


void showArr (stArr *arrP){
    
    for(int i = 0; i< arrP->elNumbers; i++){
        printf("Array em x: %d\t array em y: %d\n e angulo %f", arrP->arr[i].x, arrP->arr[i].y, arrP->arr[i].angle);   
    }
}


int main(void)
{
    int el;
    stArr array;
    printf("Input the number of points you want ");
    scanf("%d", &el);
    array.arr = malloc(el*sizeof(stPoint));
    array.elNumbers = el;
    createPoints(&array);
    showArr(&array);

    /*showArr(&array);
    centerPoints(&array);
         cx = cy = 0;
        for (int i = 0; i<array->n)*{
            cx +=array->arr[i].x;
            cy += array->arr[i].y;
        }
        cx /=array->n;
        cy /=array->n;
         for (int i = 0; i<array->n)*{
            array->arr[i].x -= cx;
            array->arr[i].y -=cy;
        }
    showArr(&array);
    calculateAngle(&array);
    ordena(&array);
    s = calcArea(&vet);
           */
          
    
        return 0;
}
