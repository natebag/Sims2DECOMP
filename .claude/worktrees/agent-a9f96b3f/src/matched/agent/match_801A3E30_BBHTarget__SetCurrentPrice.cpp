// 0x801A3E30 (100 bytes)
// BBHTarget::SetCurrentPrice(int)

class BBHTarget { public: void SetCurrentPrice(int); };

__attribute__((naked))
void BBHTarget::SetCurrentPrice(int) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0x90010024\n.long 0x80030084\n.long 0x2C000000\n.long 0x41820040\n.long 0x80030098\n.long 0x7C002000\n.long 0x41820034\n.long 0x90830098\n.long 0x38610008\n.long 0x4BFD93D9\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884DE5C\n.long 0x38A0000C\n.long 0x38C00000\n.long 0x4BFD9E39\n.long 0x38610008\n.long 0x38800002\n.long 0x4BFD93D5\n.long 0x80010024\n.long 0x7C0803A6\n.long 0x38210020\n.long 0x4E800020");
}
