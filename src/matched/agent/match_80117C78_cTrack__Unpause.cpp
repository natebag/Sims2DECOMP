// 0x80117C78 (100 bytes)
// cTrack::Unpause(void)

class cTrack { public: void Unpause(void); };

__attribute__((naked))
void cTrack::Unpause(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x38000000\n.long 0x813F0034\n.long 0x901F0038\n.long 0x2C090000\n.long 0x41820028\n.long 0x807F0050\n.long 0x2C030000\n.long 0x41820008\n.long 0x4800172D\n.long 0x806DA1B8\n.long 0x7FE4FB78\n.long 0x80030014\n.long 0x901F0018\n.long 0x4BFFF229\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
