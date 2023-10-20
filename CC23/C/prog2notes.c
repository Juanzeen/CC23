#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*aula 1
ponteiros são usados para referenciar determinada coisa da variável.
o ponteiro * referencia conteúdo
o ponteiro & referencia endereço

exemplo de aula, troca de valores de duas variáveis

void trocaValores(int *trocaA, int *trocaB){

int aux = 0;

aux = *trocaB;
*trocaB = *trocaA;
*trocaA = aux;

}

int main (void){

int a, b;
scanf("%d%d",&a,&b);
trocaValores(&a,&b);
printf("O valor de a:%d \to valor de B:%d", a,b);


return 0;
}

*/

// aula 2

//*malloc(int num_bytes) retorna um ponteiro genérico. Aloca o que for desejado na memória.
// sizeof --> retorna o número de bytes ocupado por um tipo. pode ser usado junto com o malloc
// free --> parâmetro ponteiro de memória
// não é possível calcular operações matemáticas de um número com "lixo"

/*code que ordena os elementos do vetor.
#include <stdio.h>
#include <stdlib.h>

int* defVetor(int n){ //define o vetor, o asterisco depois do tipo da função retorna um ponteiro.
    int *v, j;
    v = (int*)malloc(n*sizeof(int)); //separa um espaço na memória para que o vetor seja criado

    if(v){
        printf("Erro no malloc!!");
        exit(1);
    }

    for(j=0; j<n; j++){
        v[j] = rand()%100;
    }

    return v;
}

void mostraVetor(int n, int *v){//exibe o vetor
    int j = 0;
    printf("\nVetor: \n");
    for(j; j<n; j++){
        printf("%d\t", v[j]);
    }
}

void trocaValores(int n, int *v){//faz a organização do vetor
    int t, j, c = 0, temp;
    while(t>0){//roda até que o if não seja mais acessado
        c++;
        t= 0;
        for(j = 0; j<n; j++){
            if(v[j-1>v[j]]){    //compara o valor anterior com o valor atual do j, troca eles quando
                temp = v[j-1];
                v[j] = v[j-1];
                v[j-1] = temp;
                t++;
            }
        }

        printf("\n O vetor teve modificações %d vezes", c);
    }

}

void pivoPosCerta(int a, int b, int *v){
    int aa, pv, temp;

    aa = a;
    pv = v[a];

    while(b>a){
        while(a>b&&pv>=v[a]){
            a++;
        while(b>=0&&pv<v[b]){
            b--;}

                if(a>b){
                    temp = v[a];
                    v[a] = v[b];
                    v[b] = temp;
                    b--;
                    a++;
                }
        }
    }

    v[aa] = v[b];
}

int main (void){
    int n, *v;
    //ler entrada n
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    v = defVetor(n);
    mostraVetor(n, v);
    ordenaVetor(n, v);
    mostraVetor(n,v);
    free(v);


    return 0;
}

//Criar um programa onde é criado um vetor onde todos os valores a esquerda são menores do que o valor cedido pelo usuário
 e os da direita são maiores.*/

/*aula 3
//desenvolvimento do codigo que organiza um vetor centralizando um elemento

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

    startP = initialP;
    center = arr[initialP];
    initialP++;

    while(initialP<=finalP){
        while(center>=arr[initialP]&&initialP<=finalP)
                initialP++;

        while(finalP>=0&&center<arr[finalP])
            finalP--;

        if(initialP<finalP){
                temp = arr[initialP];
                arr[initialP] = arr[finalP];
                arr[finalP] = temp;
                finalP--;
                initialP++;
        }


    }
    arr[startP] = arr[finalP];
    arr[finalP] = center;
    return finalP;
}


 int main (void){
    int el, *arr, positionF; //pivo é o elemento que deve ser colocado na posição certa
    printf("Input the elements of the array: ");
    scanf("%d", &el);
    arr = createArr(el);
    showArr(el,arr);
    positionF = centerPos(0, el-1, arr);
    showArr(el, arr);
    printf("The center is in the positition: %d", positionF);
    free(arr);
    return 0;
 }
 retornar a posição onde fica o center na array. -> próximo trabalho*/

 /*Inicio da teoria do codigo to trabalho 3

    typedef struct stPoint{
        int x;
        int y;
        float angle;
    };

    typedef struct  *stArr
    {
     int n;
     struct stPoint *arr;   
    };

int main(void)
{
    int n;
    struct stArr *array;
    printf("Input the number of points you want ");
    scanf("%d", &n);
    /*array.arr = malloc(n*sizeof(int));
    createPoints(&array)
    showArr(&array);
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
    float calcArea(stArray *array){
        float a = 0.0;
        for(int i = 0; i <array->n; i++){
            j = (i+1)%(array->n)
            angle1 = ((array->arr[j].x - array->arr[i].x) * (array->arr[j].y + array->arr[i]))/2
            angle +=angle1
        }
        return (angle); 
        }   
        /
        return 0;
};
    
// testando typedef
//declaramos o typedef SEMPRE antes da main
//o struct pode ser criado dentro main

struct arrayTwoVariables{
    int x, y;
};

typedef struct arrayTwoVariables arrTwo; 


int main (void){

    struct aluno{
        char name[10];
        int age;
        float cr;
    };

    struct aluno juan;
    juan.name[10] = "Juan";
    juan.age = 18;
    juan.cr = 8.0;

    printf("Ola user, seu nome é %s, sua idade é %d e seu cr é: %f", juan.name, juan.age, juan.cr);

    arrTwo array;

    array.x= 10;
    array.y = 15;

    printf("O valor de x no vetor é: %d e o valor de y é: %d", array.x, array.y);

    return 0;
}*/




