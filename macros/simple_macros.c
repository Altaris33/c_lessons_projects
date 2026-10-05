#include <stdio.h>

// unlike functions, macros merely execute a text-replacement
// since they are created using the pre-processor directive 
// #define
#define ARRAY_LEN 100
#define CALCULCATE_LEN(x) (sizeof((x)) / sizeof((x)[0]))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    printf("Macros - Basics\n");

    double array[ARRAY_LEN];
    printf("Array length= %d\n\n", ARRAY_LEN);

#undef ARRAY_LEN
#define ARRAY_LEN 999

    printf("Array length = %d\n", ARRAY_LEN);

    printf("Source file: \"%s\", %d\n", __FILE__, __LINE__);
    printf("Compilation time: %s\n", __TIME__);

    // check the number of elements in the array
    int array_len = CALCULCATE_LEN(array);

    printf("array_len = %d\n", array_len);

    int a = -2, b = 5;
    printf("MAX(%d, %d): %d\n", a, b, MAX(a, b));

    int b_before = b;
    // drawback of using macro: b is actually incremented twice
    // this is a break
    printf("MAX(%d, %d): %d\n", a, b_before, MAX(a, b++)); 
    printf("b before MAX macro: %d\n", b_before);
    printf("b after MAX macro: %d\n", b);

    printf("\n");
    return 0;
}