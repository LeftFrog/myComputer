#include "../include/computer.h"

int mc_memoryInit() {
    for (int i = 0; i < MC_MEMORY_SIZE; i++) {
        mc_memory[i] = 0;
    }
    return 0;
}

int mc_memorySet(uint8_t address, int16_t value) {
    if (address > MC_MEMORY_SIZE-1 || address < 0) {
        mc_register |= MC_MEMORY_OUT_OF_BOUNDS_FLAG;
        return -1;
    }
    mc_memory[address] = value;
    return 0;
}

int mc_memoryGet(uint8_t address, int16_t* value) {
    if (address > MC_MEMORY_SIZE-1 || address < 0) {
        mc_register |= MC_MEMORY_OUT_OF_BOUNDS_FLAG;
        return -1;
    }
    *value = mc_memory[address];
    return 0;
}
