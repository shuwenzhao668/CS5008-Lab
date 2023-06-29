#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    printf("%d ", data);
    return node;
}

//PREORDER root to left to right
void preOrder(struct node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data); 
    preOrder(node->left);
    preOrder(node->right);
}

//INORDER from left to right
void inOrder(struct node* node) {
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

//POSTORDER from end of the tree from left to right
void postOrder(struct node* node) {
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

// main function to test the above functions
int main() {
    printf("Original tree construction: \n");
    struct node* root = newNode(1);
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

    printf("Preorder:\n");
    preOrder(root);

    printf("\n\nInorder:\n");
    inOrder(root);

    printf("\n\nPostorder:\n");
    postOrder(root);

    return 0;
}
