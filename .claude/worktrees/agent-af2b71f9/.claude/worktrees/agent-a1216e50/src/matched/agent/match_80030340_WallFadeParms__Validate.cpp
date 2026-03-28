// 0x80030340 (76 bytes)
// WallFadeParms::Validate(void)

class WallFadeParms { public: void Validate(void); };

__attribute__((naked))
void WallFadeParms::Validate(void) {
    asm volatile(".long 0xC1A30008\n.long 0xC0030018\n.long 0xFC006800\n.long 0x40800008\n.long 0xD1A3001C\n.long 0xC0030004\n.long 0xC1A30008\n.long 0xFC006800\n.long 0x40800008\n.long 0xD1A30004\n.long 0xC1A30004\n.long 0x3D20803D\n.long 0xC1830008\n.long 0xC0090E84\n.long 0xEDAD6028\n.long 0xEC006824\n.long 0xD1A30020\n.long 0xD0030024\n.long 0x4E800020");
}
