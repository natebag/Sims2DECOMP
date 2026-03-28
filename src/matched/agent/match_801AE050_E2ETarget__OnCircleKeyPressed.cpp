// 0x801AE050 (112 bytes)
// E2ETarget::OnCircleKeyPressed(char *, char *)

class E2ETarget { public: void OnCircleKeyPressed(char *, char *); };

__attribute__((naked))
void E2ETarget::OnCircleKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FEF0\n.long 0x7C0802A6\n.long 0x93E1010C\n.long 0x90010114\n.long 0x7C7F1B78\n.long 0x813F00D8\n.long 0x38A90001\n.long 0x2C090002\n.long 0x40820008\n.long 0x38A00000\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884DDA0\n.long 0x4CC63182\n.long 0x48130801\n.long 0x813F0080\n.long 0x38A10008\n.long 0x808D88A8\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010114\n.long 0x7C0803A6\n.long 0x83E1010C\n.long 0x38210110\n.long 0x4E800020");
}
