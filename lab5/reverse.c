// singly linked list from lab3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

typedef struct slist {
    node_t* head;
    node_t* tail;
    int size;
} slist_t;

slist_t* makeSlist() {
    slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
    if(newList == NULL) {
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;

    return newList;
}

int search(slist_t* list, int value) {
    node_t* cur = list->head;
    int pos = 1;
    while(cur != NULL) {
        if(cur->value == value) {
            return pos;
        }
        cur = cur->next;
        pos++;
    }
    return -1;
}

// insert the element at the head
void insertHead(slist_t* list, int value) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    if(list->tail == NULL) {
        list->tail = newNode;
    }
}

// insert the element at the tail
void insertTail(slist_t* list, int value) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;

    if(list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        list->size = 1;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->size++;
    }
}

// insert in the middle 
void insertMiddle(slist_t* list, int value, int position) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;

    if(position > list->size + 1 || position < 1) {
        printf("Invalid position\n");
        return;
    }

    if(position == 1) {
        insertHead(list, value);
        return;
    }

    if(position == list->size + 1) {
        insertTail(list, value);
        return;
    }

    node_t* cur = list->head;
    for(int i=1; i<position-1; i++) {
        cur = cur->next;
    } 
    // when reaching here, cur is the previous node of targeted position
    newNode->next = cur->next;
    cur->next = newNode;
    list->size++;
}

// delete the element at the head
void deleteHead(slist_t* list) {
    if(list->head == NULL) {
        printf("Linked list is already empty\n");
        return;
    }

    node_t* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;

    if(list->head == NULL) {
        list->tail = NULL;
    }
}

// delete the element at the tail
void deleteTail(slist_t* list) {
    if(list->head == NULL) {
        printf("Linked list is already empty\n");
        return;
    }
    node_t* cur = list->head;
    node_t* prev = NULL;
    while(cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    // when reaching here, cur is the last node, which should be deleted
    // prev is the second last node, which should become the last
    if(prev == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        prev->next = NULL;
        list->tail = prev;
    }
    free(cur);
    list->size--;
}

// delete the element in the middle 
void deleteMiddle(slist_t* list, int position) {
    if(position > list->size || position < 1) {
        printf("Invalid position\n");
        return;
    }
    if(position == 1) {
        deleteHead(list);
        return;
    }
    if(position == list->size) {
        deleteTail(list);
        return;
    }
    node_t* cur = list->head;
    for(int i=1; i<position-1; i++) {
        cur = cur->next;
    }
    // when reaching here, cur is the prev node of targeted position
    node_t* temp = cur->next;
    cur->next = temp->next;
    free(temp);
    list->size--;
}

void printList(slist_t* list) {
    node_t* cur = list->head;
    while(cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

node_t* reverse(node_t* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    node_t* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}


int main() {
    slist_t* list1 = makeSlist();
    int size;
    printf("Input list size: ");
    scanf("%d", &size);

    int i = 0;
    printf("Input elements of the array: \n");
    while(i < size){
        int input;
        scanf("%d", &input);
        insertTail(list1, input);
        i++;
    }
    
    printf("The list: \n");
    printList(list1);

    node_t* newNode = reverse(list1->head);
    printf("The reversed list: \n");
    while(newNode != NULL){
        printf("%d ", newNode->value);
        newNode = newNode->next;
    }

    return 0;
}