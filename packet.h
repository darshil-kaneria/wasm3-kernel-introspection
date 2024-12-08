#ifndef PACKET_H
#define PACKET_H

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

enum packet_protocol {
    TCP,
    UDP
};

struct packet_header {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_pt;
    uint16_t dst_pt;
    uint16_t len;
    uint8_t prot;
};

struct iphdr {
    uint8_t ihl;
    uint8_t version;
    uint8_t tos;
    uint16_t tot_len;
    uint16_t id;
    uint16_t frag_off;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t check;
    uint32_t saddr;
    uint32_t daddr;
};

struct sk_buff {
    unsigned int len;          // Length of the packet data
    unsigned char *data;       // Pointer to the packet data
    unsigned char *head;       // Pointer to the start of the buffer
    unsigned char *tail;       // Pointer to the end of the data
    unsigned char *end;        // Pointer to the end of the buffer
};

enum packet_op {
    DROP,
    ACCEPT
};

#endif