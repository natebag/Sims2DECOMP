// 0x8015E028 (96 bytes)
// TreeTableQuickData::Load(unsigned int, short)

class TreeTableQuickData { public: void Load(unsigned int, short); };

__attribute__((naked))
void TreeTableQuickData::Load(unsigned int, short) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x54A5043E\n.long 0x38610008\n.long 0x4BFFDAB1\n.long 0x813E0000\n.long 0x38810008\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C7E1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x3860FFCE\n.long 0x41820008\n.long 0x38600000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
