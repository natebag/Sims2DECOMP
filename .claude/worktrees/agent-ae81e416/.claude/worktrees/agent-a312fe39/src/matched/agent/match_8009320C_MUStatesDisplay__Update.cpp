// 0x8009320C (68 bytes)
// MUStatesDisplay::Update(float)

class MUStatesDisplay { public: void Update(float); };

__attribute__((naked))
void MUStatesDisplay::Update(float) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230008\n.long 0x81690098\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0080\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
