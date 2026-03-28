// 0x800779A0 (108 bytes)
// CUnlockDisplay::destroyObjects(void)

class CUnlockDisplay { public: void destroyObjects(void); };

__attribute__((naked))
void CUnlockDisplay::destroyObjects(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x817E0464\n.long 0x2C0B0000\n.long 0x41820034\n.long 0x83EB0000\n.long 0x2C0B0000\n.long 0x41820020\n.long 0x812B0084\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FEBFB79\n.long 0x4082FFD4\n.long 0x38000000\n.long 0x901E0464\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
