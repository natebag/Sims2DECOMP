// 0x801811E8 (92 bytes)
// UIButtonImages::Shutdown(void)

class UIButtonImages { public: void Shutdown(void); };

__attribute__((naked))
void UIButtonImages::Shutdown(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x806D84FC\n.long 0x2C030000\n.long 0x41820038\n.long 0x480003B1\n.long 0x816D84FC\n.long 0x2C0B0000\n.long 0x41820020\n.long 0x812B00B0\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38000000\n.long 0x900D84FC\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
