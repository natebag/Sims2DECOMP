// 0x80119AD0 (72 bytes)
// cSoundCache::KillAll(void)

class cSoundCache { public: void KillAll(void); };

__attribute__((naked))
void cSoundCache::KillAll(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3BDF00FC\n.long 0x807F0000\n.long 0x3BFF0004\n.long 0x2C030000\n.long 0x41820008\n.long 0x4BFFE28D\n.long 0x7C1FF000\n.long 0x4081FFE8\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
