// 0x80177074 (76 bytes)
// UI3D::Shutdown(void)

class UI3D { public: void Shutdown(void); };

__attribute__((naked))
void UI3D::Shutdown(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816D84CC\n.long 0x2C0B0000\n.long 0x41820028\n.long 0x812B001C\n.long 0x38800003\n.long 0x8009000C\n.long 0xA8690008\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000000\n.long 0x900D84CC\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
