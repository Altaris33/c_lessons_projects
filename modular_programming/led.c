#include <stdio.h>

#include "led.h"

void print_led_status(Led led)
{
    printf("%s", led == LED_OFF ? "LED OFF" : "LED ON");
}