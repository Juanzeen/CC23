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

void dataRegister(char charP, stList *listP)
{
    stNode *nodeF = listP->first;
    if (listP->first == NULL)
    {
        nodeF = (stNode *)malloc(sizeof(stNode));
        nodeF->character = charP;
        nodeF->frequency = 1;
        nodeF->next = NULL;
        listP->elQtt++;
        listP->first = nodeF;
    }

    else
    {
        nodeF = listP->first;
        while (nodeF)
        {
            if (nodeF->character == charP){
                    nodeF->frequency++;
                    break;}

            else
            {
                if (nodeF->character > charP)
                {
                    stNode *nodeFN = (stNode *)malloc(sizeof(stNode));
                    nodeFN->character = charP;
                    nodeFN->frequency++;
                    nodeFN->next = nodeF;

                    if (listP->last == NULL)
                        listP->first = nodeFN;
                    listP->elQtt++;
                }
            }
        }
    }
}

void showList(stNode *nodeP)
{
    while (nodeP)
    {
        printf("%c: %d \n", nodeP->character, nodeP->frequency);
    }
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
    char charL;

    myList.first = myList.last = NULL;
    myList.elQtt = 0;

    arch = fopen("Texto.txt", "r");

    if (arch == NULL)
    {
        printf("Error on the txt.");
        exit;
    }

    fscanf(arch, "%c", &charL); //
    while (feof(arch))
    {
        dataRegister(charL, &myList);
        fscanf(arch, "%c", &charL);
    }

    fclose(arch);

    showList(myList.first);

    return 0;
}