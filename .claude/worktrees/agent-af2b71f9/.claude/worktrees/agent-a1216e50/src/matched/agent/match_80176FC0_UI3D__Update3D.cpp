// 0x80176FC0 (68 bytes)
// UI3D::Update3D(void)

class UI3D { public: void Update3D(void); };

__attribute__((naked))
void UI3D::Update3D(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x83E30000\n.long 0x2C1F0000\n.long 0x41820018\n.long 0x807F001C\n.long 0x4BF00E1D\n.long 0x83FF0004\n.long 0x2C1F0000\n.long 0x4082FFF0\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
