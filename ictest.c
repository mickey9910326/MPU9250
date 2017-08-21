#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include "ASALIB\ASA_DEVICE.h"
#include "ASALIB\ASA_core_lib.h"
#include "ASALIB\ASA_SPI.h"
#include "ASALIB\ASA_DIO.h"
#include "ASALIB\ASA_STDIO.h"
#include "MPU9250.h"

uint8_t whoami();
int main() {
    ASA_STDIO_set();
    ASA_MSTR_spi_set();
    ASA_ID_init();
    ASA_ID_set(1);
    ASA_slave_cs(1);
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR));

    printf("Test for MPU9250. by LiYu 2017.08.21\n");
    printf("Get WhoAmI register, data should be 0x71.\n");

    uint8_t who = whoami();
    if (who == 0x71) {
        printf("OK! ");
    } else {
        printf("Fail! ");
    }
    printf("data is 0x%02X\n", who);

    return 0;
}

uint8_t whoami() {
    uint8_t response;
    M128_SPI_get(0,MPUREG_WHOAMI|READ_FLAG, 1, &response);

    return response;
}
