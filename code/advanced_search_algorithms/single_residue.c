#include <stdio.h>

#define SLOTS 7

int hastTable[SLOTS];

void init() {
    for(int i = 0; i < SLOTS; i++) {
        hastTable[i] = -1;
    }
}

void residue_store(int values[], int size){
    for(int i = 0; i < size; i++) {
        int slot = values[i] % SLOTS;
        if (hastTable[slot] == -1){
            hastTable[slot] = values[i];
        } else {
            printf("COLLISION!!!");
        }
    }
}

void printTable() {
    for (int i = 0; i < SLOTS; i++){
        printf("[%d] -> %d \n", i, hastTable[i]); 
    }
}

int main() {

    int test[] = {12, 27, 42};
    int sizeExample = 3;
    init();
    residue_store(test, sizeExample);
    printTable();

    return 0;
}