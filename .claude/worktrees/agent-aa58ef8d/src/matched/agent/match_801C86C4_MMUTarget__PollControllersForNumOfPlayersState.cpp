// 0x801C86C4 (92 bytes)
// MMUTarget::PollControllersForNumOfPlayersState(void)

class MMUTarget { public: void PollControllersForNumOfPlayersState(void); };

__attribute__((naked))
void MMUTarget::PollControllersForNumOfPlayersState(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BFFF9ED\n.long 0x801F0100\n.long 0x7C691B78\n.long 0x7C004800\n.long 0x41820024\n.long 0x3C60803F\n.long 0x913F0100\n.long 0x38632E10\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFAF64D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
