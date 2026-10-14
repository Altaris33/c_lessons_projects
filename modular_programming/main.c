#include <stdio.h>
#include <stdlib.h>

#include "mod1.h"
#include "mod2.h"

/*
* Compile with gcc : 
*   gcc -Wall -Wextra -std=c11 main.c led.c mod1.c mod2.c -o led_program
*/
int main(void) {
    printf("Modular Programming - With Header files\n\n");

    print_mod1();
    print_mod2();

    printf("\n");

    return 0;
}
