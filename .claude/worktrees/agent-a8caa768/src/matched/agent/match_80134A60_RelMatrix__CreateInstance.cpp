// 0x80134A60 (72 bytes)
// RelMatrix::CreateInstance(void)

class RelMatrix { public: void CreateInstance(void); };

__attribute__((naked))
void RelMatrix::CreateInstance(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x38600014\n.long 0x4819C741\n.long 0x3D208046\n.long 0x7C6B1B78\n.long 0x38000000\n.long 0x392942D8\n.long 0x912B0000\n.long 0x394B000C\n.long 0x900B0004\n.long 0x900B0008\n.long 0x900A0004\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
