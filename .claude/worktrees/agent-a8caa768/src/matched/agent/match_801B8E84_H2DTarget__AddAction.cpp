// 0x801B8E84 (68 bytes)
// H2DTarget::AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int)

class H2DTarget { public: void AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int); };

__attribute__((naked))
void H2DTarget::AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7D2B4B78\n.long 0x28040001\n.long 0x41810020\n.long 0x392300B4\n.long 0x5480103A\n.long 0x7C69002E\n.long 0x2C030000\n.long 0x4182000C\n.long 0x7D695B78\n.long 0x4BFE9511\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
