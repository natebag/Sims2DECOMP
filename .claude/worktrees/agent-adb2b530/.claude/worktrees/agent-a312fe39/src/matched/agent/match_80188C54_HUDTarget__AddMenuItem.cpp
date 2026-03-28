// 0x80188C54 (112 bytes)
// HUDTarget::AddMenuItem(int, cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, int, bool)

class HUDTarget { public: void AddMenuItem(int, cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, int, bool); };

__attribute__((naked))
void HUDTarget::AddMenuItem(int, cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, int, bool) {
    asm volatile(".long 0x9421FFD0\n.long 0x7C0802A6\n.long 0xBEE1000C\n.long 0x90010034\n.long 0x7C771B78\n.long 0x7C9E2378\n.long 0x7CBD2B78\n.long 0x7CDC3378\n.long 0x7CFB3B78\n.long 0x7D1A4378\n.long 0x7D394B78\n.long 0x83010038\n.long 0x48000139\n.long 0x1FDE00B4\n.long 0x7FA4EB78\n.long 0x7F85E378\n.long 0x7F66DB78\n.long 0x7F47D378\n.long 0x7F28CB78\n.long 0x7F09C378\n.long 0x3BDE0740\n.long 0x7C77F214\n.long 0x4BFFB2D9\n.long 0x80010034\n.long 0x7C0803A6\n.long 0xBAE1000C\n.long 0x38210030\n.long 0x4E800020");
}
