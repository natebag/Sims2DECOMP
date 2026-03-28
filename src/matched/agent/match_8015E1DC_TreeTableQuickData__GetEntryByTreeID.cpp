// 0x8015E1DC (92 bytes)
// TreeTableQuickData::GetEntryByTreeID(short, short) const

class TreeTableQuickData { public: void GetEntryByTreeID(short, short) const; };

__attribute__((naked))
void TreeTableQuickData::GetEntryByTreeID(short, short) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0004\n.long 0x2C030000\n.long 0x41820028\n.long 0x4BFEB729\n.long 0x813F0000\n.long 0x7C641B78\n.long 0xA8690078\n.long 0x8009007C\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
