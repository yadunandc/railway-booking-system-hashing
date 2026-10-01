#include <stdio.h>

#define SIZE 10

int linear[SIZE], quadratic[SIZE], doubleHash[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}

void initialize()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        linear[i] = -1;
        quadratic[i] = -1;
        doubleHash[i] = -1;
    }
}

void insertLinear(int key)
{
    int index = hashFunction(key);
    int i;

    for (i = 0; i < SIZE; i++)
    {
        index = (hashFunction(key) + i) % SIZE;

        if (linear[index] == -1)
        {
            linear[index] = key;
            return;
        }
    }
}

void insertQuadratic(int key)
{
    int index, i;

    for (i = 0; i < SIZE; i++)
    {
        index = (hashFunction(key) + i * i) % SIZE;

        if (quadratic[index] == -1)
        {
            quadratic[index] = key;
            return;
        }
    }

    printf("Booking ID %d could not be inserted "
           "using Quadratic Probing.\n", key);
}

void insertDoubleHash(int key)
{
    int index;
    int step = 1 + (key % 7);
    int i;

    for (i = 0; i < SIZE; i++)
    {
        index = (hashFunction(key) + i * step) % SIZE;

        if (doubleHash[index] == -1)
        {
            doubleHash[index] = key;
            return;
        }
    }
}

void display(int table[], char name[])
{
    int i;

    printf("\n%s\n", name);
    printf("Index\tBooking ID\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", i);

        if (table[i] == -1)
            printf("Empty\n");
        else
            printf("%d\n", table[i]);
    }
}

void search(int table[], int key, int method)
{
    int index, step, i, probes = 0;

    step = 1 + (key % 7);

    for (i = 0; i < SIZE; i++)
    {
        if (method == 1)
            index = (hashFunction(key) + i) % SIZE;
        else if (method == 2)
            index = (hashFunction(key) + i * i) % SIZE;
        else
            index = (hashFunction(key) + i * step) % SIZE;

        probes++;

        if (table[index] == key)
        {
            printf("Booking ID %d: Found, Probes = %d\n",
                   key, probes);
            return;
        }

        if (table[index] == -1)
        {
            printf("Booking ID %d: Not found, Probes = %d\n",
                   key, probes);
            return;
        }
    }

    printf("Booking ID %d: Not found, Probes = %d\n",
           key, probes);
}

int main()
{
    int ids[] = {23, 43, 13, 33, 53, 63, 73};
    int n = 7, i;
    int keys[] = {33, 73, 99};

    initialize();

    for (i = 0; i < n; i++)
    {
        insertLinear(ids[i]);
        insertQuadratic(ids[i]);
        insertDoubleHash(ids[i]);
    }

    display(linear, "Linear Probing");
    display(quadratic, "Quadratic Probing");
    display(doubleHash, "Double Hashing");

    printf("\n--- Linear Probing Search ---\n");
    for (i = 0; i < 3; i++)
        search(linear, keys[i], 1);

    printf("\n--- Quadratic Probing Search ---\n");
    for (i = 0; i < 3; i++)
        search(quadratic, keys[i], 2);

    printf("\n--- Double Hashing Search ---\n");
    for (i = 0; i < 3; i++)
        search(doubleHash, keys[i], 3);

    printf("\nLoad Factor = %d / %d = %.2f\n",
           n, SIZE, (float)n / SIZE);

    return 0;
}
