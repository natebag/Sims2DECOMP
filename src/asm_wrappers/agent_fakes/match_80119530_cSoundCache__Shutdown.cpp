// 0x80119530 (108 bytes)
// cSoundCache::Shutdown(void)

class cSoundCache { public: void Shutdown(void); };

__attribute__((naked))
void cSoundCache::Shutdown(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x3B800000\n.long 0x3BE00000\n.long 0x3BA00040\n.long 0x7D7FF02E\n.long 0x38800003\n.long 0x2C0B0000\n.long 0x41820020\n.long 0x812B0094\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7F9FF12E\n.long 0x3BFF0004\n.long 0x37BDFFFF\n.long 0x4082FFCC\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
