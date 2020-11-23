void fetchNextInstruction(void);

void fetchNextInstruction(void) {
    PC += 1;
    IR = memory[PC];
    return 0;
}
