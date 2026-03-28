// 0x801B0764 (76 bytes)
// FAMTarget::UpdateShaders(void)

class FAMTarget { public: void UpdateShaders(void); };

__attribute__((naked))
void FAMTarget::UpdateShaders(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030088\n.long 0x2C000000\n.long 0x4082000C\n.long 0x480001D5\n.long 0x48000020\n.long 0x2C000004\n.long 0x4082000C\n.long 0x48002549\n.long 0x48000010\n.long 0x2C000001\n.long 0x40820008\n.long 0x48000015\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
