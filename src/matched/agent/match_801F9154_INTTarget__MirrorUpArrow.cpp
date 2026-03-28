// 0x801F9154 (76 bytes)
// INTTarget::MirrorUpArrow(bool)

class INTTarget { public: void MirrorUpArrow(bool); };

__attribute__((naked))
void INTTarget::MirrorUpArrow(bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800300DC\n.long 0x7C002000\n.long 0x41820028\n.long 0x80030088\n.long 0x908300DC\n.long 0x2C000000\n.long 0x41820018\n.long 0x7C852378\n.long 0x80C30098\n.long 0x808D908C\n.long 0x386300C8\n.long 0x4BF845D1\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
