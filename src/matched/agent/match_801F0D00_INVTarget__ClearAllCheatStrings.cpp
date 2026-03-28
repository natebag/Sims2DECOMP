// 0x801F0D00 (72 bytes)
// INVTarget::ClearAllCheatStrings(void)

class INVTarget { public: void ClearAllCheatStrings(void); };

__attribute__((naked))
void INVTarget::ClearAllCheatStrings(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3BE3018B\n.long 0x3BC00005\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x38A00800\n.long 0x3BFF0800\n.long 0x480528BD\n.long 0x37DEFFFF\n.long 0x4082FFE8\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
