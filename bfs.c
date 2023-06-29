#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node
struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

// Queue for BFS
struct Queue {
    struct QueueNode *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    printf("%d ", data);
    return node;
}

struct QueueNode* newQueueNode(struct Node* node) {
    struct QueueNode* qNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    qNode->node = node;
    qNode->next = NULL;
    return qNode;
}

// Add a node to the rear of the queue
void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* qNode = newQueueNode(node);
    if (q->rear == NULL) {
        q->front = q->rear = qNode;
    } else {
        q->rear->next = qNode;
        q->rear = qNode;
    }
}

// Remove a node from the front of the queue
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    struct Node* node = temp->node;
    free(temp);
    return node;
}

// Traverse binary tree using BFS and print the result
void bfsTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    enqueue(q, root);
    while (q->front != NULL) {
        struct Node* node = dequeue(q);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enqueue(q, node->left);
        }
        if (node->right != NULL) {
            enqueue(q, node->right);
        }
    }
    printf("\n");
}

// Test the implementation
int main() {
    printf("Original tree construction: \n");
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
    printf("\n\n");

    printf("BFS result: \n");
    bfsTraversal(root);

    return 0;
}
