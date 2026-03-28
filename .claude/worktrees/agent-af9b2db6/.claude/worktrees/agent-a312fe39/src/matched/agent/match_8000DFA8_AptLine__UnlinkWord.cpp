// 0x8000DFA8 (80 bytes)
// AptLine::UnlinkWord(AptWord *)

class AptLine { public: void UnlinkWord(AptWord *); };

__attribute__((naked))
void AptLine::UnlinkWord(AptWord *) {
    asm volatile(".long 0x7C6B1B78\n.long 0x39200000\n.long 0x806B0004\n.long 0x2C030000\n.long 0x4D820020\n.long 0x7C032000\n.long 0x41820010\n.long 0x7C691B78\n.long 0x80630000\n.long 0x4BFFFFE8\n.long 0x2C030000\n.long 0x4D820020\n.long 0x2C090000\n.long 0x41820010\n.long 0x80030000\n.long 0x90090000\n.long 0x4E800020\n.long 0x80030000\n.long 0x900B0004\n.long 0x4E800020");
}
