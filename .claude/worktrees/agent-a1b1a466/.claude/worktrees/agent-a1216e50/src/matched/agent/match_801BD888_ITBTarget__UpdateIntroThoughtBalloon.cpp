// 0x801BD888 (108 bytes)
// ITBTarget::UpdateIntroThoughtBalloon(void)

class ITBTarget { public: void UpdateIntroThoughtBalloon(void); };

__attribute__((naked))
void ITBTarget::UpdateIntroThoughtBalloon(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D20803F\n.long 0xC1A3009C\n.long 0xC0091BD8\n.long 0xFC0D0000\n.long 0x40810040\n.long 0x3D20803F\n.long 0x80030088\n.long 0xC0091BDC\n.long 0x2C000000\n.long 0xEDAD0028\n.long 0xD1A3009C\n.long 0x41820024\n.long 0x80030094\n.long 0x2C000000\n.long 0x40820018\n.long 0x3D20803F\n.long 0xC0091BE0\n.long 0xFC0D0000\n.long 0x40800008\n.long 0x4BFFFF9D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
