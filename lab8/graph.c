#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* newNode(int value, struct node *next) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = next;
    return newNode;
}

void freeNodes(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void printAdjList(struct node* adjList[], int numOfNodes) {
    printf("Adjacency List:\n");
    for (int i = 0; i < numOfNodes; i++) {
        printf("%d: ", i);
        struct node* currentNode = adjList[i];
        while (currentNode != NULL) {
            printf("%d->", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int numOfNodes = 4;
    struct node** adjList = (struct node**)malloc(numOfNodes*sizeof(struct node*));

    //initialize adjList
    for (int i = 0; i < numOfNodes; i++) {
        adjList[i] = NULL;
    }

    int adjMatrix[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 0}
    };

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numOfNodes; i++) {
        for (int j = 0; j < numOfNodes; j++) {
            if (adjMatrix[i][j] == 1) {
                if(adjList[i]==NULL){
                    adjList[i] = newNode(j, NULL);
                } else {
                    adjList[i] = newNode(j, adjList[i]);
                }

            }
        }
    }

    printAdjList(adjList,numOfNodes);

    // Free the nodes
    for (int i = 0; i < numOfNodes; i++) {
        freeNodes(adjList[i]);
    }
    free(adjList);

    return 0;
}
