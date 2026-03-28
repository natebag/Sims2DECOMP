// 0x80117C1C (92 bytes)
// cTrack::Pause(void)

class cTrack { public: void Pause(void); };

__attribute__((naked))
void cTrack::Pause(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x38000001\n.long 0x813F0034\n.long 0x901F0038\n.long 0x2C090000\n.long 0x41820020\n.long 0x807F0050\n.long 0x2C030000\n.long 0x41820008\n.long 0x48001739\n.long 0x806DA1B8\n.long 0x7FE4FB78\n.long 0x4BFFF2F5\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
