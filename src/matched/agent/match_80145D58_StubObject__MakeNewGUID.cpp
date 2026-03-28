// 0x80145D58 (72 bytes)
// StubObject::MakeNewGUID(void)

class StubObject { public: void MakeNewGUID(void); };

__attribute__((naked))
void StubObject::MakeNewGUID(void) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBFA10014\n.long 0x90010024\n.long 0x3BC10008\n.long 0x7FC3F378\n.long 0x4BF37951\n.long 0x4BF37A29\n.long 0x7C7D1B78\n.long 0x480FD535\n.long 0x801E0004\n.long 0x7C001A78\n.long 0x7FA30278\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBBA10014\n.long 0x38210020\n.long 0x4E800020");
}
