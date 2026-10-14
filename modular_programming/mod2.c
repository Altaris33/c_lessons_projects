#include <stdio.h>
#include "mod2.h"

void print_mod2()
{
    Led led = LED_OFF;
    printf("Mod 2. Led status: ");
    print_led_status(led);
    printf("\n");
}