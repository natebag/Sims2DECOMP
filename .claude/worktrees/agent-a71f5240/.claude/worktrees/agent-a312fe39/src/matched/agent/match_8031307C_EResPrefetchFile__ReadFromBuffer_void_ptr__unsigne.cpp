// 0x8031307C (68 bytes)
// EResPrefetchFile::ReadFromBuffer(void *, unsigned int)

class EResPrefetchFile { public: void ReadFromBuffer(void *, unsigned int); };

__attribute__((naked))
void EResPrefetchFile::ReadFromBuffer(void *, unsigned int) {
    asm volatile(".long 0x39600000\n.long 0x7C0B2840\n.long 0x40800034\n.long 0x81230030\n.long 0x396B0001\n.long 0x7C0B2840\n.long 0x88090000\n.long 0x39290001\n.long 0x98040000\n.long 0x91230030\n.long 0x38840001\n.long 0x81230040\n.long 0x39290001\n.long 0x91230040\n.long 0x4180FFD4\n.long 0x7D635B78\n.long 0x4E800020");
}
