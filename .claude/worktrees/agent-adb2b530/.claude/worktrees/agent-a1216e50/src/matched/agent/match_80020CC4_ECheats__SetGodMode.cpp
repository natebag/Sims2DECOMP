// 0x80020CC4 (68 bytes)
// ECheats::SetGodMode(bool)

class ECheats { public: void SetGodMode(bool); };

__attribute__((naked))
void ECheats::SetGodMode(bool) {
    asm volatile(".long 0x7C842379\n.long 0x41820034\n.long 0x3D208047\n.long 0x38000001\n.long 0x39295DCC\n.long 0x900903D8\n.long 0x900903D0\n.long 0x900903C0\n.long 0x900903C8\n.long 0x900903CC\n.long 0x900903BC\n.long 0x900903F0\n.long 0x900903DC\n.long 0x4E800020\n.long 0x3D208047\n.long 0x908961C8\n.long 0x4E800020");
}
