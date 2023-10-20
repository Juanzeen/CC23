#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct sPoint{
        float x, y;
        float angle;
    }stPoint; //colocamos outro nome no final para que nao seja necessario passar struct nome_struct

typedef struct  sArr{
    int elNumbers;
    stPoint *arr;   
    }stArr;

stPoint createPoints(stArr *arrP){
    stPoint center;
    srand(time(NULL));
    for(int i = 0; i < arrP->elNumbers; i++){
        arrP->arr[i].x =  rand()%100;
        arrP->arr[i].y =  rand()%100;
        center.x +=  arrP->arr[i].x;
        center.y +=  arrP->arr[i].y;
    }

    center.x/= arrP->elNumbers;
    center.y/= arrP->elNumbers;
    center.angle = 0.0;

    return center;
}   


void showArr (stArr *arrP){
     for(int i = 0; i< arrP->elNumbers; i++){
        printf("Array em x: %f\t array em y: %f\n e angulo %f", arrP->arr[i].x, arrP->arr[i].y, arrP->arr[i].angle);   
        }
}

void createArrays(stArr *arrP, stPoint center){
        for (int i = 0; i<arrP->elNumbers; i++){
            arrP->arr[i].x -= center.x;
            arrP->arr[i].y -=center.y;
        }
}

float calcAngle(stArr *arrP){
    float h, cos, arccos;

    for (int i = 0; i< arrP->elNumbers; i++){
        h = sqrt(arrP->arr[i].x * arrP->arr[i].x ); //pitagoras
        cos = arrP->arr[i].x/h;
        arccos = acos(cos);

        if(cos >=0){

            if(arrP->arr[i].y<0){
                arccos = 360 - arccos;
                free(arrP);
            }

            else{

                if(arrP->arr[i].y<0)
                    arccos = 180 + arccos;

                else 
                    arccos = 180 - arccos;
            }
        }
    }
}

/* float calcArea(stArr *arrP){
    int angle, angle1, j; 
        float a = 0.0;
        for(int i = 0; i <arrP->elNumbers; i++){
            j = (i+1)%(arrP->elNumbers);
            angle1 = ((arrP->arr[j].x - arrP->arr[i].x) * (arrP->arr[j].y + arrP->arr[i].y))/2;
            angle +=angle1;
        }
        return angle ; 
        }  */


int main(void)
{
    int el;
    stArr array;
    stPoint center;
    printf("Input the number of points you want ");
    scanf("%d", &el);
    array.arr = malloc(el*sizeof(stPoint));
    array.elNumbers = el;
    center = createPoints(&array);
    showArr(&array);
    createArrays(&array, center);
    showArr(&array);
    calcAngle(&array);
    showArr(&array);
    /*ordena(&array); quick sort aqui papai
    s = calcArea(&vet);
           */
          
    
        return 0;
}
