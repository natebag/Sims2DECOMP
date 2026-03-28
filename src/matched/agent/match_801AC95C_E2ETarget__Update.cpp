// 0x801AC95C (84 bytes)
// E2ETarget::Update(void)

class E2ETarget { public: void Update(void); };

__attribute__((naked))
void E2ETarget::Update(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x48000579\n.long 0x2C030000\n.long 0x4082000C\n.long 0x7FE3FB78\n.long 0x480005F5\n.long 0x3D20803F\n.long 0x38000001\n.long 0xC029F7F8\n.long 0x901F0088\n.long 0x4BE8BD7D\n.long 0x4BE8BE29\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
