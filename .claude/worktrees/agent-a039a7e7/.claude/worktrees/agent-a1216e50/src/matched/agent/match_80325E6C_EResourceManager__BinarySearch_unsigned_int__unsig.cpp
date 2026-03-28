// 0x80325E6C (100 bytes)
// EResourceManager::BinarySearch(unsigned int, unsigned int *, int)

class EResourceManager { public: void BinarySearch(unsigned int, unsigned int *, int); };

__attribute__((naked))
void EResourceManager::BinarySearch(unsigned int, unsigned int *, int) {
    asm volatile(".long 0x7C6A1B78\n.long 0x7CA52B79\n.long 0x41820054\n.long 0x38A5FFFF\n.long 0x38600000\n.long 0x7C032800\n.long 0x4080002C\n.long 0x7C032A14\n.long 0x7C0B0E70\n.long 0x5569103A\n.long 0x7C09202E\n.long 0x7C005040\n.long 0x4080000C\n.long 0x386B0001\n.long 0x4BFFFFDC\n.long 0x7D655B78\n.long 0x4BFFFFD4\n.long 0x5469103A\n.long 0x7C09202E\n.long 0x7C005000\n.long 0x4D820020\n.long 0x3860FFFF\n.long 0x4E800020\n.long 0x3860FFFF\n.long 0x4E800020");
}
