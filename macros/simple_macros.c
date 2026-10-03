#include <stdio.h>

#define ARRAY_LEN 100

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
    

    printf("\n");
    return 0;
}