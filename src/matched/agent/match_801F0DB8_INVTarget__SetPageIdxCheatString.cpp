// 0x801F0DB8 (68 bytes)
// INVTarget::SetPageIdxCheatString(char *, int)

class INVTarget { public: void SetPageIdxCheatString(char *, int); };

__attribute__((naked))
void INVTarget::SetPageIdxCheatString(char *, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x3D608040\n.long 0x88C9018A\n.long 0x7C832378\n.long 0x88A90189\n.long 0x388B9A70\n.long 0x38C60001\n.long 0x38A50001\n.long 0x4CC63182\n.long 0x480EDAA1\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
