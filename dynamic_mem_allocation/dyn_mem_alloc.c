#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * These are the core dynamic memory functions:
 *  Function	Purpose
    malloc()	allocate memory
    calloc()	allocate zero-initialized memory
    realloc()	resize an allocation
    free()	    release allocated memory
 */

typedef struct Person {
    char name[50];
    int age;
} Person;

int main() {

    // Allocating an array with a fixed number of elements, e.g. a fixed size in memory
    /*int numbers[100];

    numbers[0] = 2;
    numbers[1] = 56;
    numbers[2] = 90;
    numbers[2] = 4;

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    */

    // malloc : allocate dynamic memory
    // Allocate one integer
    printf("===========================================\n");
    printf("======== Dynamic Memory Allocation ========\n");
    printf("===========================================\n");
    printf("malloc(): allocate memory dynamically\n");
    int *p = malloc(sizeof(int));

    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // using the allocated memory
    *p = 42;

    printf("%d\n", *p);

    // releasing the memory
    free(p);


    // Allocating an array dynamically
    int n;

    printf("How many numbers? ");
    scanf("%d", &n);

    int *numbers_2 = malloc(n * sizeof(int));

    // equivalent to numbers_2 == NULL
    if (!numbers_2)
    {
        printf("Array of int allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        numbers_2[i] = i * 10;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers_2[i]);
    }
    printf("\n");
    printf("--------------------------\n");

    free(numbers_2);


    // calloc : the main diff is that it init all the bytes to 0
    printf("calloc(): alloc & zero-init memory\n");
    int *numbers_3 = calloc(4, sizeof(int));

    if (numbers_3 == NULL)
    {
        return 1;
    }

    for (size_t i = 0; i < 4; i++)
    {
        printf("%d ", numbers_3[i]);
    }
    printf("\n");
    printf("--------------------------\n");

    free(numbers_3);

    // realloc : resizing memory
    printf("realloc(): realloc memory e.g. resize memory\n");
    int size = 3;

    int *numbers_4 = malloc(size * sizeof(int));

    if (numbers_4 == NULL)
    {   
        printf("Allocation failed.\n");
        return 1;
    }
    
    numbers_4[0] = 1;
    numbers_4[1] = 2;
    numbers_4[2] = 3;

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", numbers_4[i]);
    }
    printf("\n");
    printf("--------------------------\n");

    int new_size = 5;

    int *temp = realloc(numbers_4, new_size * sizeof(int));

    if (temp == NULL)
    {
        printf("Re-allocation failed.\n");
        return 1;
    }

    numbers_4 = temp;

    numbers_4[3] = 4;
    numbers_4[4] = 5;

    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ", numbers_4[i]);
    }
    printf("\n");
    printf("--------------------------\n");

    free(numbers_4);

    // A useful sizeof style
    int nb = 4;
    // alternative of malloc(nb * sizeof(int))
    // *numbers points to an int
    int *new_array = malloc(nb * sizeof *new_array);

    // Dynamic allocation with structures
    printf("Dynamic allocation with structures\n");
    Person *person = malloc(sizeof *person);

    if (!person)
    {
        printf("Error allocating struct\n");
        return 1;
    }

    strcpy(person->name, "Alice");
    person->age = 25;
    printf("Person name: %s\n", person->name);
    printf("Person age: %d\n", person->age);
    free(person);

    return 0;
}