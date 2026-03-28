// 0x803C3918 (112 bytes)
// TArray<ESMSStrip, TArrayERModelAllocator>::Construct(ESMSStrip *, int)

class TArray<ESMSStrip, TArrayERModelAllocator> { public: void Construct(ESMSStrip *, int); };

__attribute__((naked))
void TArray<ESMSStrip, TArrayERModelAllocator>::Construct(ESMSStrip *, int) {
    asm volatile(".long 0x3964FFFF\n.long 0x2C040000\n.long 0x4D820020\n.long 0x38000000\n.long 0x392000FF\n.long 0x38630034\n.long 0x2C0B0000\n.long 0x9003FFCC\n.long 0x396BFFFF\n.long 0x9003FFD0\n.long 0x9003FFD4\n.long 0x9003FFD8\n.long 0x9003FFDC\n.long 0x9003FFE0\n.long 0x9003FFE4\n.long 0x9003FFE8\n.long 0x9003FFEC\n.long 0x9923FFF0\n.long 0x9923FFF1\n.long 0x9923FFF2\n.long 0x9923FFF3\n.long 0xB003FFF4\n.long 0x9803FFF7\n.long 0x9803FFF6\n.long 0x9003FFF8\n.long 0x9803FFFC\n.long 0x4082FFAC\n.long 0x4E800020");
}
