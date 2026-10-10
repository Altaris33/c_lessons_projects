#include <stdio.h>

#define LOG_INFO
#define BUFFER_SIZE 1024

int main()
{
    printf("Macros - Conditional Compilation Directives\n");

// the preprocessor checks if SOME_MACRO is defined
#ifdef SOME_MACRO
    printf("SOME_MACRO exists\n");
#endif

// the preprocessor checks if LOG_INFO is defined
#ifdef LOG_INFO
    printf("This is an info.\n");
#else
    printf("This should print.\n");
#endif

#if defined BUFFER_SIZE && BUFFER_SIZE > 2048
    printf("The buffer is huge. Do something.\n");
#elif defined BUFFER_SIZE
    printf("The buffer is ok.\n");    
#else 
    printf("The buffer size is not defined.\n");    
#endif

    printf("\n");
    return 0;
}