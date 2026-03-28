// 0x80188BF4 (96 bytes)
// HUDTarget::AddMenu(int, cXObject *, BString2 &, unsigned int, ERShader *)

class HUDTarget { public: void AddMenu(int, cXObject *, BString2 &, unsigned int, ERShader *); };

__attribute__((naked))
void HUDTarget::AddMenu(int, cXObject *, BString2 &, unsigned int, ERShader *) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBF21000C\n.long 0x9001002C\n.long 0x7C791B78\n.long 0x7C9E2378\n.long 0x7CBD2B78\n.long 0x7CDC3378\n.long 0x7CFB3B78\n.long 0x7D1A4378\n.long 0x480001A1\n.long 0x1FDE00B4\n.long 0x7FA4EB78\n.long 0x7F85E378\n.long 0x7F66DB78\n.long 0x7F47D378\n.long 0x3BDE0740\n.long 0x7C79F214\n.long 0x4BFFB265\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBB21000C\n.long 0x38210028\n.long 0x4E800020");
}
