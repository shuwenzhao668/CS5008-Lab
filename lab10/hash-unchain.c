#include <stdio.h>
#include <stdlib.h>

struct HashTable {
    int size;
    int *table;
};

int hash_function(int key, int size) {
    return key % size;
}

int double_hash_function(int key, int size) {
    return 7 - (key % 7);
}


int prob_Linear(struct HashTable *hash_table, int key, int i){
    int h1 = hash_function(key, hash_table->size);
    return (h1 + i) % hash_table->size;
}

int prob_Quadratic(struct HashTable *hash_table, int key, int i){
    int h1 = hash_function(key, hash_table->size);
    return (h1 + i * i) % hash_table->size;
}

int prob_Double(struct HashTable *hash_table, int key, int i){
    int h1 = hash_function(key, hash_table->size);
    int h2 = double_hash_function(key, hash_table->size);
    return (h1 + i * h2) % hash_table->size;
}

void insert_Linear(struct HashTable *hash_table, int key){
    for (int i = 0; i < hash_table->size; i++) {
        int index = prob_Linear(hash_table, key, i);
        if (hash_table->table[index] == -1) {
            hash_table->table[index] = key;
            return;
        }
    }
    printf("Hash table is full, cannot insert %d\n", key);
}
void insert_Quadratic(struct HashTable *hash_table, int key){
    for (int i = 0; i < hash_table->size; i++) {
        int index = prob_Quadratic(hash_table, key, i);
        if (hash_table->table[index] == -1) {
            hash_table->table[index] = key;
            return;
        }
    }
    printf("Hash table is full, cannot insert %d\n", key);
}
void insert_Double(struct HashTable *hash_table, int key){
    for (int i = 0; i < hash_table->size; i++) {
        int index = prob_Double(hash_table, key, i);
        if (hash_table->table[index] == -1) {
            hash_table->table[index] = key;
            return;
        }
    }
    printf("Hash table is full, cannot insert %d\n", key);
}

void print_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        printf("Chain[%d] -> ", i);
        int temp = hash_table->table[i];
        printf("%d \n", temp);
    }
}

int main() {
    int size;
    printf("Enter the hash table size: ");
    scanf("%d", &size);
    struct HashTable hash_table;
    hash_table.size = size;
    hash_table.table = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        hash_table.table[i] = -1;
    }

    printf("Choose probing method:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing\n");
    printf("Enter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);

    printf("Enter the number of values to insert: ");
    int num_values;
    scanf("%d", &num_values);
    if(size < num_values){
        printf("The table size is not large enough for the values");
        return 0;
    }
    
    printf("Enter the values:\n");
    for (int i = 0; i < num_values; i++) {
        int value;
        scanf("%d", &value);
        switch (choice) {
            case 1:
                insert_Linear(&hash_table, value);
                break;
            case 2:
                insert_Quadratic(&hash_table, value);
                break;
            case 3:
                insert_Double(&hash_table, value);
                break;
            default:
                printf("Invalid choice. Exiting...\n");
                free(hash_table.table);
                return 1;
        }
    }

    printf("Hash table contents:\n");
    // for (int i = 0; i < size; i++) {
    //     if (hash_table.table[i] != -1) {
    //         printf("Index %d: %d\n", i, hash_table.table[i]);
    //     }
    // }
    print_hash_table(&hash_table);

    free(hash_table.table);
    return 0;
}