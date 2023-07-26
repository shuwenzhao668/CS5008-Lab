#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct HashTable {
    int size;
    struct Node **table;
};

unsigned int hash_function(int key, int size) {
    return key % size;
}

struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert(struct HashTable *hash_table, int data) {
    unsigned int index = hash_function(data, hash_table->size);
    struct Node *new_node = create_node(data);
    struct Node *cur = hash_table->table[index];
    if (cur == NULL) {
        hash_table->table[index] = new_node;
    } else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

void print_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        printf("Chain[%d] -> ", i);
        struct Node *temp = hash_table->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void free_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        struct Node *temp = hash_table->table[i];
        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(hash_table->table);
}


int main() {
    int chain_size, num_values;

    printf("Chain Size:\n");
    scanf("%d", &chain_size);

    printf("Number of values:\n");
    scanf("%d", &num_values);

    struct HashTable hash_table;
    hash_table.size = chain_size;
    hash_table.table = (struct Node **) calloc(chain_size, sizeof(struct Node *));

    printf("Input Values:\n");
    for (int i = 0; i < num_values; i++) {
        int value;
        scanf("%d", &value);
        insert(&hash_table, value);
    }

    printf("\nThe table:\n");
    print_hash_table(&hash_table);

    free_hash_table(&hash_table);

    return 0;
}