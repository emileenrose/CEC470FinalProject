#define NOP_OPCODE 0x18
#define HALT_OPCODE 0x19
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void fetchNextInstruction(void);
void executeInstruction(void);


// Declare variables
unsigned char memory[65536];
unsigned char ACC = 0;    // Accumulator
unsigned char IR = 0;    // Instruction Register
unsigned int MAR = 0;    // Memory Address Register
unsigned int PC = 0;    // Program Counter
unsigned int operand = 0;    // Avoid reading out of file

int test(void);

int main(void) {
  test();
  return 0;
}

// test function and read in file
int test(void) {
  string line;
  ifstream read_memory;
  int i = 0;

  read_memory.open("mem_in.txt")
  while (std::getline(read_memory, line)) {
    istringstream stream_in((line));
    for (unsigned hex_to_bin; stream_in >> hex >> hex_to_bin;)
      memory[i++] = hex_to_bin;
  }
  while(PC < 65536 && (memory[PC]) != HALT_OPCODE){
    fetchNextInstruction();
    executeInstruction();
  }

  FILE *output
  output = fopen("mem_out.txt", "w");
  for (unsigned int i = 0; i < 65536;) {
    for (int k = 0; k < 16 && i < 65536; k++)
      fprintf(output, "%02X", memory[i++]);
    fprintf(output, "\n");
  }
  fclose(output);
  return 0;
}

void fetchNextInstruction(void) {
  IR = memory[PC++];

  if (IR & 0x80) { // Math OPCODE

    if ((IR & 0x0c) == 0x0c) // Destination: memory
      PC += 2

    switch (IR & 0x03) { // Source

      case 3: // Constant
        if ((IR & 0x08) == 0x08) // 16-bit destination
          PC++;
        PC++;
        break;

      case 4: // Memory
        PC += 2;
        break:
    }
  } // End if math OPCODE

  else if ((IR & 0xf0) == 0) { // Memory
    if ((IR & 2) == 0) { // Operand used
      PC++;
      if (((IR & 1) == 0) || ((IR & 4) == 4)) // Address is operand or register is MAR
        PC++;
    }
  } // End if memory OPCODE

  else if ((IR & 0xF8) == 0x10) // Branches
    PC += 2;

  // All else is either a "No Operation", "Halt", or illegal opcode,
  // in which case do nothing.
}
