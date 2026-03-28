// 0x801811A0 (72 bytes)
// UIButtonImages::Startup(void)

class UIButtonImages { public: void Startup(void); };

__attribute__((naked))
void UIButtonImages::Startup(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800D84FC\n.long 0x2C000000\n.long 0x40820024\n.long 0x386000B4\n.long 0x4814FFF5\n.long 0x48000085\n.long 0x7C601B78\n.long 0x900D84FC\n.long 0x48000115\n.long 0x806D84FC\n.long 0x48000389\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
