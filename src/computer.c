#include "../include/computer.h"

int memoryInit() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
    return 0;
}

int memorySet(uint8_t address, int16_t value) {
    if (address > MEMORY_SIZE || address < 0) {
        computerRegister |= MEMORY_OUT_OF_BOUNDS_FLAG;
        return -1;
    }
    memory[address] = value;
}
