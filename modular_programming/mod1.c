#include <stdio.h>
#include "mod1.h"

void print_mod1()
{
    Led led = LED_ON;
    printf("Mod 1. Led status: ");
    print_led_status(led);
    printf("\n");
}