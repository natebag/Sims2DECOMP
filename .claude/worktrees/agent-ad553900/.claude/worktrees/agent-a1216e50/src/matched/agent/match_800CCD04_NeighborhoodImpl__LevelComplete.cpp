// 0x800CCD04 (80 bytes)
// NeighborhoodImpl::LevelComplete(int)

class NeighborhoodImpl { public: void LevelComplete(int); };

__attribute__((naked))
void NeighborhoodImpl::LevelComplete(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x813F0000\n.long 0xA8690018\n.long 0x8009001C\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C1E1800\n.long 0x40810008\n.long 0xB3DF0084\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
