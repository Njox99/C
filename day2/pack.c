#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* Embedded-style struct — exact sizes matter! */
typedef struct
{
    uint8_t status;    /* 0-255 flag byte */
    uint16_t port;     /* 0-65535 network port */
    uint32_t ip_addr;  /* IPv4 address */
    int64_t timestamp; /* Unix time (post-2038 safe) */
} NetworkPacket;

int main(void)
{
    NetworkPacket pkt = {
        .status = 0xFF,
        .port = 8080,
        .ip_addr = 0xC0A80001, /* 192.168.0.1 */
        .timestamp = 1700000000LL};

    printf("Packet size : %zu bytes\n", sizeof(NetworkPacket));
    printf("Status      : 0x%" PRIx8 "\n", pkt.status);
    printf("Port        : %" PRIu16 "\n", pkt.port);
    printf("Timestamp   : %" PRId64 "\n", pkt.timestamp);
    return 0;
}