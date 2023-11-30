#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    char character;
    int frequency;
    struct Node *next;
} stNode;

typedef struct List
{
    int elQtt;
    stNode *first;
    stNode *last;
} stList;

stNode *createNode(char charP)
{
    stNode *node;
    node = (stNode *)malloc(sizeof(stNode));
    node->character = charP;
    node->frequency = 1;
    node->next = NULL;
    return node;
}

void dataRegister(char charP, stList *listP)
{
    stNode *node, *prevNode, *newNode;
    prevNode = NULL;
    node = listP->first;

    if (node == NULL)
    {
        listP->first = createNode(charP);
        listP->elQtt++;
    }

    else
    {
        while (node){
            if (node->character == charP)
            {
                node->frequency++;
                break;
            }

            else
            {
               if (node->character > charP)
                {
                    newNode = createNode(charP);
                    newNode->next = node;
                    listP->elQtt++;

                   if(prevNode)
                        prevNode->next = newNode;

                   else
                        listP->first = newNode;
                    break;
                }

                else {
                    prevNode = node;
                    node = node->next;
                }
            }
        }      
    }

    if(node == NULL){
        newNode = createNode(charP);
        newNode->next = NULL;
        listP->elQtt +=1;
            if(prevNode){prevNode->next = newNode;}
    }

}

void showList(stNode *nodeP)
{
    while (nodeP)
    {
        printf("%c: %d \n", nodeP->character, nodeP->frequency);
        nodeP = nodeP->next;
    }
}

void switchPosition(stNode *nodeP, stList *listP){
    stNode *newNode,*prevNode;
    newNode = listP->first;
    prevNode = NULL;

    if(!newNode){
        nodeP->next = NULL;
        listP->first = nodeP;
        return;
    }

    while(newNode){
        if(newNode->frequency > nodeP->frequency){
            if(prevNode){
                prevNode->next = nodeP;
                nodeP->next = newNode;
            }

            else{
                nodeP->next = listP->first;
                listP->first = nodeP;
            }
            return;
        }

        prevNode = newNode;
        newNode = newNode->next;
    }

    if(prevNode){
        prevNode->next = nodeP;
        nodeP->next = NULL;
    }

}

void organizing(stList *listP){
    stList newList;
    newList.first = newList.last = NULL;
    newList.elQtt = 0;
    
    stNode *node, *next;
    node = listP->first;
    while(node){
        next = node->next;
        node->next = NULL;
        switchPosition(node, &newList);
        node = next;
    }

    listP->first = newList.first;
    listP->last = newList.last;
    listP->elQtt = newList.elQtt;

}

void freeList(stList *listP)
{
    stNode *node = listP->first; // recebe o endereço do primeiro elemento
    while (node)
    {
        listP->first = node->next; // vai se repetir até que o node pare de ser verdadeiro
        free(node);                // quando ele parar, não existirá próximo
        node = listP->first;       // vai receber o endereço do próximo, para que o loop se satisfaça
    }
}

int main(void)
{
    FILE *arch;
    stList myList; // não coloca ponteiro para colocar dentro da função e passar o parametro com &
    char charM;

    myList.first = myList.last = NULL;
    myList.elQtt = 0;

    arch = fopen("Texto.txt", "r");

    if (arch == NULL)
    {
        printf("Error on the txt.");
        exit(0);
    }

    fscanf(arch, "%c", &charM); //
    while (!feof(arch))
    {
        dataRegister(charM, &myList);
        fscanf(arch, "%c", &charM);
    }

    fclose(arch);
    showList(myList.first);
    organizing(&myList);
    printf("----------------");
    showList(myList.first);
    freeList(&myList);
    return 0;
}