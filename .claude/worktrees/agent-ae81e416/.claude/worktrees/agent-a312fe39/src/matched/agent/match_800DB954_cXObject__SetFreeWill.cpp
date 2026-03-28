// 0x800DB954 (76 bytes)
// cXObject::SetFreeWill(bool)

class cXObject { public: void SetFreeWill(bool); };

__attribute__((naked))
void cXObject::SetFreeWill(bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DAC08\n.long 0x906D8358\n.long 0x2C0B0000\n.long 0x41820024\n.long 0x812B0000\n.long 0x3880001E\n.long 0xA8AD835A\n.long 0xA8690038\n.long 0x8009003C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
