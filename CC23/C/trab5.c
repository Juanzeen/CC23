#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{//estrutura nó
    char character;
    int frequency;
    struct Node *next;
} stNode;

typedef struct List//estrutura lista
{
    int elQtt;
    stNode *first;
    stNode *last;
} stList;

stNode *createNode(char charP)//funcao que cria os nós, parametro é o caracter lido no arquivo
{
    stNode *node; //cria o no
    node = (stNode *)malloc(sizeof(stNode));//alocação de memoria do nó
    node->character = charP; //declara que o conteúdo (caracter) do nó é o caracter do arquivo
    node->frequency = 1;//como o nó acabou de ser criado, ele só aparece uma vez, logo frequencia = 1
    node->next = NULL;//inicializa o proximo do nó como nulo
    return node;// retorna o no
}

void dataRegister(char charP, stList *listP)//registra os nós na lista
{
    stNode *node, *prevNode, *newNode;//cria um novo no, um no anterior e reserva uma variavel para o primeiro no da lista
    prevNode = NULL; //no anterior é nulo
    node = listP->first; //nó recebe o primeiro nó da lista

    if (!node)//se o primeiro no da lista for nulo
    {
        listP->first = createNode(charP);//criamos o primeiro no da lista
        listP->elQtt++;//aumentamos em 1 a quantidade de elementos da nossa lista
    }

    else //se existir um primeiro no na lista
    {
        while (node){//enquanto esse no existir
            if (node->character == charP)//se o caracter lido for igual ao caracter do primeiro no
            {
                node->frequency++;//a frequencia do no aumenta, pois se o conteudo é igual, o no é igual
                break;//nó existiu, caracter foi igual, somamos um na frequencia desse nó e quebramos o while
            }

            else //char do no diferente do char do primero elemento da lista, resulta em nós diferentes
            {
               if (node->character > charP)//se o tamanho do char do primeiro no da lista for maior que o char lido
                {
                    newNode = createNode(charP);//criamos um novo no com esse char lido
                    newNode->next = node;//o proximo do novo nó criado é o primeiro nó da nossa lista
                                         // uma vez que o char lido é menor que o char desse nó
                    listP->elQtt++;//acrescentamos um no na lista, adicionamos mais um na quantidade de elementos da lista

                   if(prevNode)//se existir um no anterior
                        prevNode->next = newNode;//o proximo desse no anterior será o nosso novo no, que é menor que o first

                   else//se nao existe no anterior
                        listP->first = newNode;//o primeiro no da lista passa a ser o novo no
                    break;//quebra o while
                }

                else {//se o novo caracter foi maior do que o caracter do no que ja esta na lista
                    prevNode = node; //o anterior passa a ser o que ja existia na lista (first), que continua sendo o proprio first
                    node = node->next;//o que até então era o first, passa a ser o proximo, já que passa a ter um antes dele
                }
            }
        }      
    }

    if(node == NULL){//caso o no seja nulo, pode ocorrer quando atribuímos a ele o next e o next nao existe
        newNode = createNode(charP);//criaremos um novo no
        newNode->next = NULL;//declaramos o proximo desse novo no como nulo
        listP->elQtt +=1;//aumentamos em um o total de elementos na lista
            if(prevNode){prevNode->next = newNode;}//se existir um no anterior, o proximo dele será o novo no que acabou de ser criado
    }

}

void showList(stNode *nodeP)//funcao que mostra a lista
{
    while (nodeP)//enquanto existir um no
    {
        printf("%c: %d \n", nodeP->character, nodeP->frequency);//mostramos char e frequencia
        nodeP = nodeP->next;//o no vira o proximo no da lista, o que é a condição de break do while
                            //uma vez que em algum momento esse proximo nao existira e o nodeP será nulo
    }
}

void switchPosition(stNode *nodeP, stList *listP){//funcao para organizacao com base na frequencia
    stNode *newNode,*prevNode;//criamos um novo no e um no anterior
    newNode = listP->first;//o novo no começa sendo o primeiro no da lista
    prevNode = NULL;//o no anterior começa nulo

    if(!newNode){//se nao existir um newNode, ou seja, se nao existir um first na lista
        nodeP->next = NULL;//o proximo no do nosso no de parametro é nulo
        listP->first = nodeP;//o primeiro no da lista passa a ser o nosso no de parametro
        return;
    }

    while(newNode){//enquanto existir um novo no
        if(newNode->frequency > nodeP->frequency){//se esse novo no aparecer mais vezes do que o no passado como parametro
            if(prevNode){//se tiver no anterior
                prevNode->next = nodeP;//o proximo do no anterior é o no parametro, que aparece menos que o novo no
                nodeP->next = newNode;//o proximo do no parametro é o novo no, ja que ele aparece mais vezes
            }

            else{//se nao tiver no anterior
                nodeP->next = listP->first;//o proximo do no parametro é o first da lista
                listP->first = nodeP;//o primeiro da lista é o no parametro
            }
            return;
        }
        
        else{//freq do novo no menor que a do no parametro
        prevNode = newNode;//no anterior recebe novo no
        newNode = newNode->next;//novo no recebe o proximo dele
        }
    }

    if(prevNode){//se existir no anterior
        prevNode->next = nodeP;//o proximo do no anterior é o no parametro
        nodeP->next = NULL;//proximo do no parametro é nulo
    }

}

void organizing(stList *listP){//organizando a lista pela frequencia
    stList newList;//criamos uma nova lista
    newList.first = newList.last = NULL;
    newList.elQtt = 0;
    
    stNode *node, *next;//criamos dois novos nos
    node = listP->first;//no recebe o primeiro elemento da nossa lista
    while(node){//enquanto o no existir
        next = node->next;//o proximo é o proximo do no
        node->next = NULL;//o proximo do no passa a ser nulo
        switchPosition(node, &newList);//usamos a funcao de trocar posicao e passamos para ela o first da lista junto com a nova lista
        node = next;//nosso no passa a ser o proximo
    }

    listP->first = newList.first;//trocamos os dados da primeira lista pelos da segunda
    listP->last = newList.last;
    listP->elQtt = newList.elQtt;

}

void freeList(stList *listP)//liberar a lista 
{
    stNode *node = listP->first; // recebe o endereço do primeiro elemento da lista
    while (node)//enquanto a lista tiver um primeiro elemento
    {
        listP->first = node->next; // o primeiro elemento se torna o proximo
        free(node);                // liberamos o no que declaramos como primeiro elemento da lista
        node = listP->first;       // depois de liberar o antigo no, colocamos novamente o primeiro elemento da lista nesse no
                                   //pois o primeiro elemento da lista foi alterado para o que era o proximo
    }
}

int main(void)
{
    FILE *arch; //declarando arquivo
    stList myList; // não coloca ponteiro para colocar dentro da função e passar o parametro com &
    char charM;//char que será lido no arquivo

    myList.first = myList.last = NULL;//iniciando lista
    myList.elQtt = 0;

    arch = fopen("Texto.txt", "r");//abrindo texto como leitura

    if (!arch)//caso nao exista arquivo
    {
        printf("Error on the txt.");
        exit(0);
    }

    //situacao quando o arquivo existe
    fscanf(arch, "%c", &charM); //lemos o primeiro char do arquivo
    while (!feof(arch))//enquanto o arquivo nao acabar
    {
        dataRegister(charM, &myList);//registramos um no para o char lido antes do while
        fscanf(arch, "%c", &charM);//lemos um novo char
    }

    fclose(arch);//fecha arquivo
    showList(myList.first);
    organizing(&myList);//organizando lista pela frequencia
    printf("----------------");
    showList(myList.first);
    freeList(&myList);//liberando lista
    return 0;
}