// 0x800D2A68 (76 bytes)
// MemoryCardCache::GetSubSectionMemoryUsage(NghLayout *, int)

class MemoryCardCache { public: void GetSubSectionMemoryUsage(NghLayout *, int); };

__attribute__((naked))
void MemoryCardCache::GetSubSectionMemoryUsage(NghLayout *, int) {
    asm volatile(".long 0x81630004\n.long 0x38600000\n.long 0x2C0B0000\n.long 0x4D820020\n.long 0x54A9103A\n.long 0x7D69582E\n.long 0x2C0B0000\n.long 0x4D820020\n.long 0x28050001\n.long 0x41810018\n.long 0x1D250018\n.long 0x80040004\n.long 0x7D290214\n.long 0x80690004\n.long 0x4E800020\n.long 0x812B0004\n.long 0x800B000C\n.long 0x7C604A14\n.long 0x4E800020");
}
