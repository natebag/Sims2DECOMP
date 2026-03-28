// 0x80095638 (68 bytes)
// StartScreenVars::Update(float)

class StartScreenVars { public: void Update(float); };

__attribute__((naked))
void StartScreenVars::Update(float) {
    asm volatile(".long 0xC0030000\n.long 0x3D20803E\n.long 0xC1A30008\n.long 0xC1898790\n.long 0xEC00082A\n.long 0xEDAD082A\n.long 0xD0030000\n.long 0xD1A30008\n.long 0xFC0D6000\n.long 0x4C620B82\n.long 0x4C830020\n.long 0x8003000C\n.long 0xEC0D6028\n.long 0xD0030008\n.long 0x68000001\n.long 0x9003000C\n.long 0x4E800020");
}
