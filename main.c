#include <stdio.h>

#define SIZE 11
#define EMPTY -1

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void initialize(int table[]) {
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;
}

void displayTable(int table[]) {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == EMPTY)
            printf("[%d] -> EMPTY\n", i);
        else
            printf("[%d] -> %d\n", i, table[i]);
    }
}

void linearProbing(int keys[], int n) {
    int table[SIZE];
    initialize(table);

    printf("\n=== LINEAR PROBING ===\n");
    printf("Insertion Trace:\n");

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hash1(key);
        int probes = 1;

        while (table[index] != EMPTY) {
            index = (index + 1) % SIZE;
            probes++;
        }

        table[index] = key;
        printf("%d: hash=%d, final_index=%d, probes=%d\n",
               key, hash1(key), index, probes);
    }

    printf("\nFinal Hash Table:\n");
    displayTable(table);

    int searchKeys[] = {23, 73, 93};
    printf("\nSearch Results:\n");

    for (int s = 0; s < 3; s++) {
        int key = searchKeys[s];
        int index = hash1(key);
        int probes = 1;

        while (table[index] != EMPTY && table[index] != key) {
            index = (index + 1) % SIZE;
            probes++;
        }

        if (table[index] == key)
            printf("%d -> Found, probes=%d\n", key, probes);
        else
            printf("%d -> Not Found, probes=%d\n", key, probes);
    }
}

void quadraticProbing(int keys[], int n) {
    int table[SIZE];
    initialize(table);

    printf("\n=== QUADRATIC PROBING ===\n");
    printf("Insertion Trace:\n");

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = hash1(key);
        int probes = 0;

        for (int j = 0; j < SIZE; j++) {
            index = (hash1(key) + j * j) % SIZE;
            probes++;

            if (table[index] == EMPTY) {
                table[index] = key;
                break;
            }
        }

        printf("%d: hash=%d, final_index=%d, probes=%d\n",
               key, hash1(key), index, probes);
    }

    printf("\nFinal Hash Table:\n");
    displayTable(table);

    int searchKeys[] = {23, 73, 93};
    printf("\nSearch Results:\n");

    for (int s = 0; s < 3; s++) {
        int key = searchKeys[s];
        int probes = 0;
        int found = 0;

        for (int j = 0; j < SIZE; j++) {
            int index = (hash1(key) + j * j) % SIZE;
            probes++;

            if (table[index] == key) {
                found = 1;
                break;
            }

            if (table[index] == EMPTY)
                break;
        }

        if (found)
            printf("%d -> Found, probes=%d\n", key, probes);
        else
            printf("%d -> Not Found, probes=%d\n", key, probes);
    }
}

void doubleHashing(int keys[], int n) {
    int table[SIZE];
    initialize(table);

    printf("\n=== DOUBLE HASHING ===\n");
    printf("Insertion Trace:\n");

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index;
        int probes = 0;

        for (int j = 0; j < SIZE; j++) {
            index = (hash1(key) + j * hash2(key)) % SIZE;
            probes++;

            if (table[index] == EMPTY) {
                table[index] = key;
                break;
            }
        }

        printf("%d: h1=%d, h2=%d, final_index=%d, probes=%d\n",
               key, hash1(key), hash2(key), index, probes);
    }

    printf("\nFinal Hash Table:\n");
    displayTable(table);

    int searchKeys[] = {23, 73, 93};
    printf("\nSearch Results:\n");

    for (int s = 0; s < 3; s++) {
        int key = searchKeys[s];
        int probes = 0;
        int found = 0;

        for (int j = 0; j < SIZE; j++) {
            int index = (hash1(key) + j * hash2(key)) % SIZE;
            probes++;

            if (table[index] == key) {
                found = 1;
                break;
            }

            if (table[index] == EMPTY)
                break;
        }

        if (found)
            printf("%d -> Found, probes=%d\n", key, probes);
        else
            printf("%d -> Not Found, probes=%d\n", key, probes);
    }
}

int main() {
    int keys[] = {23, 43, 13, 33, 53, 63, 73};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("RAILWAY BOOKING SYSTEM USING HASHING\n");
    printf("Hash Table Size = %d\n", SIZE);
    printf("Number of Booking IDs = %d\n", n);
    printf("Load Factor = %.3f (%.1f%%)\n", (double)n / SIZE,
           (double)n * 100 / SIZE);

    linearProbing(keys, n);
    quadraticProbing(keys, n);
    doubleHashing(keys, n);

    return 0;
}
