#include "pico/stdlib.h"
#include <stdio.h>

//GPIO LEDS
#define GPIO_LED_RED 13
#define GPIO_LED_GREEN 11
#define GPIO_LED_BLUE 12

//GPIO BUZZER
#define GPIO_BUZZER 21

int main() {

stdio_init_all();

//Inicialização do buzzer
gpio_init(GPIO_BUZZER);

//Definindo o buzzer como saída
gpio_set_dir(GPIO_BUZZER, GPIO_OUT);


//Inicialização dos LEDs
gpio_init(GPIO_LED_RED);
gpio_init(GPIO_LED_GREEN);
gpio_init(GPIO_LED_BLUE);

//Definindo os LEDs como saída
gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);



while (true)
{

    char input = getchar(); // Aguarda entrada pelo terminal

    //Desliga todos os leds
    gpio_put(GPIO_LED_RED, 0);
    gpio_put(GPIO_LED_GREEN, 0);
    gpio_put(GPIO_LED_BLUE, 0);

    

    switch (input)
    {
    case 'r':
        gpio_put(GPIO_LED_RED, 1);
        printf("GPIO: 13\n");
        break;
    case 'g':
        gpio_put(GPIO_LED_GREEN, 1);
        printf("GPIO: 12\n");
        break;
    case 'b':
        gpio_put(GPIO_LED_BLUE, 1);
        printf("GPIO: 11\n");
        break;
    case 't':
        gpio_put(GPIO_LED_RED, 1);
        gpio_put(GPIO_LED_GREEN, 1);
        gpio_put(GPIO_LED_BLUE, 1);
        break;
    case 'x':
        gpio_put(GPIO_BUZZER, 1);
        sleep_ms(2000);
        gpio_put(GPIO_BUZZER, 0);
        printf("GPIO: 21\n");
        break; 
    default:
        printf("Valor invalido!\n");
        break;
  }


}

return 0;

}
