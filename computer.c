#include "computer.h"

int memoryInit() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
}
