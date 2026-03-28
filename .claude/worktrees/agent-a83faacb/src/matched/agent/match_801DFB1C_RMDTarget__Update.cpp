// 0x801DFB1C (124 bytes)
// RMDTarget::Update(void)

class RMDTarget { public: void Update(void); };

__attribute__((naked))
void RMDTarget::Update(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x800B0084\n.long 0x2C000000\n.long 0x41820054\n.long 0x800B0088\n.long 0x2C000002\n.long 0x40820048\n.long 0x800B00AC\n.long 0x2C000000\n.long 0x4082003C\n.long 0x3D20803F\n.long 0xC1AB00A8\n.long 0xC1895448\n.long 0xFC0D6000\n.long 0x40810028\n.long 0xC00D9750\n.long 0xEC0D0028\n.long 0xFC006000\n.long 0xD00B00A8\n.long 0x4C620382\n.long 0x40830010\n.long 0x38000001\n.long 0x900B00AC\n.long 0x480006A9\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
