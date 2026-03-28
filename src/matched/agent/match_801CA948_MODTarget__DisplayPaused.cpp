// 0x801CA948 (104 bytes)
// MODTarget::DisplayPaused(void)

class MODTarget { public: void DisplayPaused(void); };

__attribute__((naked))
void MODTarget::DisplayPaused(void) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0x93E10024\n.long 0x9001002C\n.long 0x7C7F1B78\n.long 0x801F0094\n.long 0x2C000000\n.long 0x40820038\n.long 0x38610008\n.long 0x4BFB28C9\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884317C\n.long 0x38A00001\n.long 0x38C00000\n.long 0x4BFB2DD9\n.long 0x38000006\n.long 0x38610008\n.long 0x901F00E0\n.long 0x38800002\n.long 0x4BFB28BD\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0x83E10024\n.long 0x38210028\n.long 0x4E800020");
}
