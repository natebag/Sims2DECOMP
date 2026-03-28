// 0x800BA8F4 (120 bytes)
// cGZSnd::reset(void)

class cGZSnd { public: void reset(void); };

__attribute__((naked))
void cGZSnd::reset(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x809F001C\n.long 0x2C040000\n.long 0x41820028\n.long 0x816D983C\n.long 0x812B0000\n.long 0x80090094\n.long 0xA8690090\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000000\n.long 0x901F001C\n.long 0x817F0018\n.long 0x2C0B0000\n.long 0x41820018\n.long 0x812B0004\n.long 0x38000000\n.long 0x3929FFFF\n.long 0x912B0004\n.long 0x901F0018\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
