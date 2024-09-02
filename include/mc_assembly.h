//
// Created by Leonov Oleksandr on 9/2/24.
//

#ifndef MC_ASSEMBLY_H
#define MC_ASSEMBLY_H

// I/O instructions
#define READ 0b0010000
#define WRITE 0b0010001

// Loading/unloading instructions to the accumulator
#define LOAD 0b0100000
#define STORE 0b0100001

// Arithmetic instructions
#define ADD 0b0110000
#define SUB 0b0110001
#define DIVIDE 0b0110010
#define MUL 0b0110011

// Transfer instructions
#define JUMP 0b1000000
#define JNEG 0b1000001
#define JZ 0b1000010
#define HALT 0b1000011

// User instructions
#define NOT 0b1010001
#define AND 0b1010010
#define OR 0b1010011
#define XOR 0b1010100
#define JNS 0b1010101
#define JC 0b1010110
#define JNC 0b1010111
#define JP 0b1011000
#define JNP 0b1011001
#define CHL 0b1100000
#define SHR 0b1100001
#define RCL 0b1100010
#define RCR 0b1100011
#define NEG 0b1100100
#define ADDC 0b1100101
#define SUBC 0b1100110
#define LOGLC 0b1100111
#define LOGRC 0b1101000
#define RCCL 0b1101001
#define RCCR 0b1110000
#define MOVA 0b1110001
#define MOVR 0b1110010
#define MOVCA 0b1110011
#define MOVCR 0b1110100

#endif //MC_ASSEMBLY_H
