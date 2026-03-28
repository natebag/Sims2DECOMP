// 0x80016FB8 (68 bytes)
// ESimsCam::ApplyPan(float)

class ESimsCam { public: void ApplyPan(float); };

__attribute__((naked))
void ESimsCam::ApplyPan(float) {
    asm volatile(".long 0xC003044C\n.long 0x3D20803D\n.long 0xEDA0082A\n.long 0xD1A3044C\n.long 0xC189E330\n.long 0xFC0D6000\n.long 0x40810010\n.long 0xEC0D6028\n.long 0xD003044C\n.long 0x4E800020\n.long 0x3D20803D\n.long 0xC009E334\n.long 0xFC0D0000\n.long 0x4C800020\n.long 0xEC0D602A\n.long 0xD003044C\n.long 0x4E800020");
}
