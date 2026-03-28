// 0x80327A9C (76 bytes)
// EResourceMap::Search(unsigned int)

class EResourceMap { public: void Search(unsigned int); };

__attribute__((naked))
void EResourceMap::Search(unsigned int) {
    asm volatile(".long 0x81630004\n.long 0x39400000\n.long 0x7C0A5800\n.long 0x40800038\n.long 0x81030000\n.long 0x7C0A5A14\n.long 0x7C030E70\n.long 0x54691838\n.long 0x7C09402E\n.long 0x7C040040\n.long 0x4081000C\n.long 0x39430001\n.long 0x4800000C\n.long 0x4C800020\n.long 0x7C6B1B78\n.long 0x7C0A5800\n.long 0x4180FFD4\n.long 0x7D435378\n.long 0x4E800020");
}
