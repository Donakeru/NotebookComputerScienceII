#include <stdio.h>
#include <stdlib.h>

#define SLOTS 10

// Nodo de la lista enlazada
typedef struct Node {
    int key;
    struct Node *next;
} Node;

// Tabla hash (cada posición apunta al inicio de una lista)
Node *hashTable[SLOTS];

// Inicializar la tabla
void init() {
    for (int i = 0; i < SLOTS; i++) {
        hashTable[i] = NULL;
    }
}

// Función hash
int hash_function(int key) {
    return key % SLOTS;
}

// Insertar una llave
void insert(int key) {
    int slot = hash_function(key);

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    newNode->key = key;
    newNode->next = hashTable[slot];

    // Insertar al inicio de la lista
    hashTable[slot] = newNode;
}

// Buscar una llave
int search(int key) {
    int slot = hash_function(key);

    Node *current = hashTable[slot];

    while (current != NULL) {
        if (current->key == key) {
            return 1; // Encontrado
        }
        current = current->next;
    }

    return 0; // No encontrado
}

// Imprimir la tabla hash
void printTable() {
    for (int i = 0; i < SLOTS; i++) {

        printf("[%d] -> ", i);

        Node *current = hashTable[i];

        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("NULL\n");
    }
}

// Liberar memoria
void freeTable() {
    for (int i = 0; i < SLOTS; i++) {

        Node *current = hashTable[i];

        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }

        hashTable[i] = NULL;
    }
}

int main() {

    init();

    insert(234);
    insert(543);
    insert(1);
    insert(11);
    insert(21);
    insert(31);

    printTable();

    int key = 234;

    if (search(key))
        printf("\nLa llave %d SI existe.\n", key);
    else
        printf("\nLa llave %d NO existe.\n", key);

    freeTable();

    return 0;
}