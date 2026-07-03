#include <stdio.h>

#define MOD2 5
#define SLOTS 7

int hastTable[SLOTS];

void init() {
    for(int i = 0; i < SLOTS; i++) {
        hastTable[i] = -1;
    }
}

int mod(int key, int mod) {
    return key % mod;
}

void residue_store(int values[], int size){
    for(int i = 0; i < size; i++) {
        int slot = mod(values[i], SLOTS);
        if (hastTable[slot] == -1){
            hastTable[slot] = values[i];
        } else {
            int slot = mod(values[i], MOD2);
            if (hastTable[slot] == -1) {
                hastTable[slot] = values[i];
            } else {
                printf("COLLISION!!\n");
            }
        }
    }
}

void printTable() {
    for (int i = 0; i < SLOTS; i++){
        printf("[%d] -> %d \n", i, hastTable[i]); 
    }
}

int main() {

    int test[] = {12, 27, 42, 35};
    int sizeExample = 4;
    init();
    residue_store(test, sizeExample);
    printTable();

    return 0;
}