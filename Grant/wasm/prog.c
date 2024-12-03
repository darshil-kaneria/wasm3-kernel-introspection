// prog.c

#include <stdint.h>

// Import the print_int function from module "custom"
__attribute__((import_module("custom"), import_name("print_int")))
extern void print_int(int32_t x);

// Declare the __heap_base symbol provided by the linker
extern uint32_t __heap_base;

// Heap management variables
uint32_t heap_base = 0;
uint32_t heap_top = 0;

// Exported alloc function
__attribute__((export_name("alloc")))
uint32_t alloc(uint32_t n) {
    // Initialize heap_base if it's not set
    if (heap_base == 0) {
        heap_base = __heap_base;
        // Align heap_base to 8 bytes
        heap_base = (heap_base + 7) & ~7;
        heap_top = heap_base;
    }

    uint32_t addr = heap_top;
    heap_top += n;

    // Note: Memory growth is not handled here for simplicity

    return addr;
}

__attribute__((import_module("custom"), import_name("print_int")))
extern void print_int(int32_t x);

// Exported sum function
__attribute__((export_name("sum")))
uint32_t sum() {
    uint32_t total = 0;

    // Create an array of 10 integers
    int32_t array[10];

    // Initialize the array and print values
    for (uint32_t i = 0; i < 10; i++) {
        array[i] = i;
        print_int(array[i]);
        total += array[i];
    }

    return total;
}
