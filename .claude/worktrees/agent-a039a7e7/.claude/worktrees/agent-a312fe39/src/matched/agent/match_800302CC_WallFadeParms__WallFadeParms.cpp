// 0x800302CC (116 bytes)
// WallFadeParms::WallFadeParms(char *, float, float, bool)

class WallFadeParms { public: void WallFadeParms(char *, float, float, bool); };

__attribute__((naked))
void WallFadeParms::WallFadeParms(char *, float, float, bool) {
    asm volatile(".long 0x3D20803D\n.long 0xED220828\n.long 0xC1490E74\n.long 0x3D40803D\n.long 0x3D20803D\n.long 0x3D00803D\n.long 0xED0A4824\n.long 0x3CE0803D\n.long 0xC1690E70\n.long 0x3D608046\n.long 0xC18A0E78\n.long 0x7C691B78\n.long 0xC1A80E7C\n.long 0x396BB2B8\n.long 0xC0070E80\n.long 0x38000001\n.long 0x9169002C\n.long 0x90090000\n.long 0xD169000C\n.long 0xD1890014\n.long 0xD1A90018\n.long 0xD009001C\n.long 0x90A90028\n.long 0xD0490004\n.long 0xD0290008\n.long 0xD1490010\n.long 0xD1290020\n.long 0xD1090024\n.long 0x4E800020");
}
