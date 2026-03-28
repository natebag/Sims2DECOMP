// 0x801498B0 (116 bytes)
// TreeTable::GetIndexOfResource(short) const

class TreeTable { public: void GetIndexOfResource(short) const; };

__attribute__((naked))
void TreeTable::GetIndexOfResource(short) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C852378\n.long 0x807F0000\n.long 0x38800000\n.long 0x2C030000\n.long 0x41820008\n.long 0x8083FFFC\n.long 0x1C840024\n.long 0x7C832214\n.long 0x4826490D\n.long 0x7C631B79\n.long 0x41820020\n.long 0x813F0000\n.long 0x3C0038E3\n.long 0x60008E39\n.long 0x7D291850\n.long 0x7D2901D6\n.long 0x7D231670\n.long 0x48000008\n.long 0x3860FFFF\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
