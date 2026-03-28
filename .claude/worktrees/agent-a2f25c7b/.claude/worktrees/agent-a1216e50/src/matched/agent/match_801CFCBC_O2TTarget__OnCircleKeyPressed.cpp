// 0x801CFCBC (116 bytes)
// O2TTarget::OnCircleKeyPressed(char *, char *)

class O2TTarget { public: void OnCircleKeyPressed(char *, char *); };

__attribute__((naked))
void O2TTarget::OnCircleKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FEF0\n.long 0x7C0802A6\n.long 0x93E1010C\n.long 0x90010114\n.long 0x7C7F1B78\n.long 0x813F0088\n.long 0x38A90001\n.long 0x2C090002\n.long 0x40820008\n.long 0x38A00000\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884DDA0\n.long 0x4CC63182\n.long 0x4810EB95\n.long 0x813F0080\n.long 0x3C80803F\n.long 0x38843F00\n.long 0x38A10008\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010114\n.long 0x7C0803A6\n.long 0x83E1010C\n.long 0x38210110\n.long 0x4E800020");
}
