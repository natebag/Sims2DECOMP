// 0x80076000 (76 bytes)
// SkinCompositor::InitSkinTexture(void)

class SkinCompositor { public: void InitSkinTexture(void); };

__attribute__((naked))
void SkinCompositor::InitSkinTexture(void) {
    asm volatile(".long 0x80030010\n.long 0xA12DACF0\n.long 0x2C000000\n.long 0x4182000C\n.long 0xA00D8236\n.long 0x48000008\n.long 0xA00D8234\n.long 0x7C0901D6\n.long 0xB0030000\n.long 0x39400000\n.long 0x81230018\n.long 0x81690014\n.long 0x91430004\n.long 0x880B0019\n.long 0x2C000000\n.long 0x4D820020\n.long 0x38000001\n.long 0x90030004\n.long 0x4E800020");
}
