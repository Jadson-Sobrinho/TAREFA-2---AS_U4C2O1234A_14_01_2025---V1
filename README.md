**Jadson da Silva Sobrinho - GRUPO 6/Aline (Subgrupo 5)**

**Link do vídeo ensaio:** https://1drv.ms/v/c/3d08bb3b4f0e8bcd/EdcTemhuttdBolj5Y_gkJ64BmlUQJixtfU0myJGyWCGqSw?e=GBfHiq

# Instruções de uso do programa

Deve-se usar o programa PuTTY ou equivalente para dar os comandos ao microcontrolador;

Selecionar o tipo de conexão (connection type) como serial;

Verificar em qual linha serial (serial line) o componente esta inserido;

Configurar o velocidade (Speed) em 115200;

Clicar em "Open".

***OBS: O programa já deve estar gravado no microcontrolador*** 

# Documentação do Código de Controle de GPIO no Raspberry Pi Pico

## Introdução
Este documento descreve o funcionamento do código que controla LEDs RGB e um buzzer conectados ao Raspberry Pi Pico W. O programa utiliza a biblioteca `pico/stdlib.h` para configurar e operar os GPIOs, permitindo que os periféricos sejam ativados ou desativados com base em entradas recebidas via terminal.

## Resumo do Funcionamento
- **LEDs RGB:** Controlados individualmente ou em conjunto por comandos enviados pelo terminal.
- **Buzzer:** Emitido um som por um período fixo (2 segundos) quando acionado por comando.

## Definição dos Pinos GPIO
Os pinos GPIO utilizados estão definidos como macros para facilitar alterações futuras:

- `GPIO_LED_RED`: Pino 13 (LED Vermelho)
- `GPIO_LED_GREEN`: Pino 11 (LED Verde)
- `GPIO_LED_BLUE`: Pino 12 (LED Azul)
- `GPIO_BUZZER`: Pino 21 (Buzzer)

## Inicialização
1. Configuração da comunicação serial com `stdio_init_all()`.
2. Inicialização dos GPIOs para os LEDs e o buzzer com `gpio_init()`.
3. Definição do modo dos pinos como saída utilizando `gpio_set_dir()`.

## Laço Principal
O programa entra em um laço infinito (`while (true)`), onde:

1. **Entrada do Usuário:** O programa aguarda um comando pelo terminal utilizando `getchar()`.
2. **Ação Correspondente:** Com base na entrada, uma ação é executada para controlar os LEDs ou o buzzer. A tabela abaixo descreve os comandos aceitos:

| Comando | Ação                                   |
|---------|------------------------------------------|
| `r`     | Liga o LED Vermelho (GPIO 13).           |
| `g`     | Liga o LED Verde (GPIO 11).              |
| `b`     | Liga o LED Azul (GPIO 12).               |
| `t`     | Liga todos os LEDs simultaneamente.      |
| `x`     | Aciona o buzzer por 2 segundos (GPIO 21).|
| Outro   | Exibe mensagem de "Valor invalido!".     |

3. **Desligamento Automático:** Antes de ativar qualquer LED, todos os LEDs são desligados para garantir que apenas o desejado fique aceso.

## Trechos de Código Importantes

### Configuração de GPIOs
```c
// Inicialização do buzzer
gpio_init(GPIO_BUZZER);
gpio_set_dir(GPIO_BUZZER, GPIO_OUT);

// Inicialização dos LEDs
gpio_init(GPIO_LED_RED);
gpio_init(GPIO_LED_GREEN);
gpio_init(GPIO_LED_BLUE);

gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);
```

### Lógica do Controle
```c
char input = getchar(); // Aguarda entrada pelo terminal

// Desliga todos os LEDs antes de ativar qualquer um
gpio_put(GPIO_LED_RED, 0);
gpio_put(GPIO_LED_GREEN, 0);
gpio_put(GPIO_LED_BLUE, 0);

switch (input) {
    case 'r':
        gpio_put(GPIO_LED_RED, 1);
        printf("GPIO: 13\n");
        break;
    case 'g':
        gpio_put(GPIO_LED_GREEN, 1);
        printf("GPIO: 11\n");
        break;
    case 'b':
        gpio_put(GPIO_LED_BLUE, 1);
        printf("GPIO: 12\n");
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
```

