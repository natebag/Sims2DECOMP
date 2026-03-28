// 0x801CA9B0 (84 bytes)
// MODTarget::DisplayFastForward(void)

class MODTarget { public: void DisplayFastForward(void); };

__attribute__((naked))
void MODTarget::DisplayFastForward(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0094\n.long 0x2C000000\n.long 0x40820024\n.long 0x3C80803F\n.long 0x387F00C8\n.long 0x38843168\n.long 0x38A00001\n.long 0x38C00000\n.long 0x4BFB2D79\n.long 0x38000006\n.long 0x901F00E4\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
