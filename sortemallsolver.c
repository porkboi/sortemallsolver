#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef uint32_t qubit_vector;

typedef uint8_t bit_vector;

typedef uint8_t index_t;

bit_vector create_bv() {
    return (bit_vector) 0;
}

qubit_vector create_qbv() {
    return ((create_bv() << 24) | (create_bv() << 16) | (create_bv() << 8) | create_bv());
}

bit_vector bv_get(qubit_vector d, index_t i) {
    uint32_t mask = ((uint32_t) 15) << i*8;
    uint32_t val =  d & mask;
    return (bit_vector) val >> i*8;
}

qubit_vector edit_qbv(qubit_vector b, index_t i, bit_vector c) {
    uint32_t mask = ((int32_t) -16) << i*8;
    uint32_t insert = ((uint32_t) c) << i*8;
    uint32_t val = (uint32_t) b & mask;
    return (qubit_vector) val | insert;
}

