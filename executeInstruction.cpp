#define NOP_OPCODE 0x18
#define HALT_OPCODE 0x19
#define MATH_OPCODE 0x80
#define MATH_FUN_OPCODE 0x70
#define AND_OPCODE 0x00
#define OR_OPCODE 0x10
#define XOR_OPCODE 0x20
#define ADD_OPCODE 0x30
#define SUB_OPCODE 0x40
#define INC_OPCODE 0x50
#define DEC_OPCODE 0x60
#define NOT_OPCODE 0x70
#define MATH_DES_OPCODE 0x0c
#define MATH_DES_IND_OPCODE 0x00
#define MATH_DES_ACC_OPCODE 0x04
#define MATH_DES_ADR_OPCODE 0x08
#define MATH_DES_MEM_OPCODE 0x0c
#define MATH_SRC_OPCODE 0x03
#define MATH_SRC_IND_OPCODE 0x00
#define MATH_SRC_ACC_OPCODE 0x01
#define MATH_SRC_CON_OPCODE 0x02
#define MATH_SRC_MEM_OPCODE 0x03

void executeInstruction(void);

void executeInstruction(void) {
    if ((IR & MATH_OPCODE) == MATH_OPCODE) {
        switch (IR & MATH_FUN_OPCODE) {
            case AND_OPCODE:
                switch (IR & MATH_DES_OPCODE) {
                    case MATH_DES_IND_OPCODE:
                        
                }
        }
    }
}
