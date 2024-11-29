#include "../include/mc_computer.h"
#include "../include/mc_assembly.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_INSTRUCTION 127

bool instructionLookup[MAX_INSTRUCTION + 1] = { false };

void initInstructionLookup() {
    uint8_t instructions[] = {
        READ, WRITE, LOAD, STORE, ADD, SUB, DIVIDE, MUL, JUMP, JNEG, JZ, HALT, NOT, AND,
        OR, XOR, JNS, JC, JNC, JP, JNP, CHL, SHR, RCL, RCR, NEG, ADDC, SUBC, LOGLC, LOGRC,
        RCCL, RCCR, MOVA, MOVR, MOVCA, MOVCR
    };
    int instructionCount = sizeof(instructions) / sizeof(instructions[0]);

    for (int i = 0; i < instructionCount; i++) {
        instructionLookup[instructions[i]] = true;
    }
}

bool isValidInstruction(uint8_t instruction) {
    if (instruction <= MAX_INSTRUCTION) {
        return instructionLookup[instruction];
    }
    return false;
}

int mc_initComputer() {
    mc_memoryInit();
    mc_registerInit();
    initInstructionLookup();
    return 0;
}

int mc_memoryInit() {
    for (int i = 0; i < MC_MEMORY_SIZE; i++) {
        mc_memory[i] = 0;
    }
    return 0;
}

int mc_memorySet(uint8_t address, int16_t value) {
    if (address > MC_MEMORY_SIZE-1) {
        mc_register |= MC_MEMORY_OUT_OF_BOUNDS_FLAG;
        return -1;
    }
    mc_memory[address] = value;
    return 0;
}

int mc_memoryGet(uint8_t address, int16_t* value) {
    if (address > MC_MEMORY_SIZE-1) {
        mc_register |= MC_MEMORY_OUT_OF_BOUNDS_FLAG;
        return -1;
    }
    *value = mc_memory[address];
    return 0;
}

int mc_memorySave(char* filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return -1;
    }
    if (fwrite(mc_memory, sizeof(int16_t), MC_MEMORY_SIZE, file) != MC_MEMORY_SIZE) {
        fclose(file);
        return -2;
    }
    fclose(file);
    return 0;
}

int mc_memoryLoad(char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }
    if(fread(mc_memory, sizeof(int16_t), MC_MEMORY_SIZE, file) != MC_MEMORY_SIZE) {
        fclose(file);
        return -2;

    }
    fclose(file);
    return 0;
}

int mc_registerInit() {
    mc_register = 0;
    return 0;
}

int mc_registerSet(uint8_t registerNumber, uint8_t value) {
    if (registerNumber > MC_INVALID_INSTRUCTION_FLAG) {
        return -1;
    }
    if (value) {
        mc_register |= registerNumber;
    } else {
        mc_register &= ~registerNumber;
    }
    return 0;
}

int mc_registerGet(uint8_t registerNumber, uint8_t* value) {
    if (registerNumber > MC_INVALID_INSTRUCTION_FLAG) {
        return -1;
    }
    if (registerNumber & mc_register) {
        *value = 1;
    } else {
        *value = 0;
    }
    return 0;
}

int mc_commandEncode(uint8_t command, uint8_t operand, uint16_t* value) {
    if (!isValidInstruction(command)) {
        mc_register |= MC_INVALID_INSTRUCTION_FLAG;
        return -1;
    }
    if (operand > 100) {
        return -2;
    }
    *value = (command << 7) | operand;
    return 0;
}

int mc_commandDecode(uint16_t value, uint8_t* command, uint8_t* operand) {
    *command = (value >> 7) & 0b1111111;
    *operand = value & 0b1111111;
    return 0;
}
