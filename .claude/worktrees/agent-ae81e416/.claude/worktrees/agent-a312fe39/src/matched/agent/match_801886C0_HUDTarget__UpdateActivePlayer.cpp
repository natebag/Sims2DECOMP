// 0x801886C0 (100 bytes)
// HUDTarget::UpdateActivePlayer(int, bool)

class HUDTarget { public: void UpdateActivePlayer(int, bool); };

__attribute__((naked))
void HUDTarget::UpdateActivePlayer(int, bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3D208047\n.long 0x5484103A\n.long 0x39295DCC\n.long 0x7CBF2B78\n.long 0x392900BC\n.long 0x7D69202E\n.long 0x2C0B0000\n.long 0x41820024\n.long 0x812B0004\n.long 0xA8690308\n.long 0x8009030C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FE4FB78\n.long 0x4BFA10F9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
