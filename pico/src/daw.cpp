#include "hardware/clocks.h"
#include "hardware/dma.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/spi.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"
#include <stdio.h>

#include "spi_link.h"

void print_status()
{
    printf("nominal\n");
}

void read_stdin()
{
    int c;
    while (true) {
        c = getchar_timeout_us(0);
        if (c == PICO_ERROR_TIMEOUT)
            break;
        else if (c == '?')
            print_status();
    }
}

int main()
{
    stdio_init_all();

    spi_link_init();
    puts("Hello, world!");

    uint8_t data[16] = {};

    while (true) {
        spi_write_blocking(SPI_PORT, data, 16);
        read_stdin();
    }

    return 0;
}
