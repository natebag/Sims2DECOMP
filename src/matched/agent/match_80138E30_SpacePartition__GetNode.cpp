// 0x80138E30 (64 bytes)
// SpacePartition::GetNode(int)

class SpacePartition { public: void GetNode(int); };

__attribute__((naked))
void SpacePartition::GetNode(int) {
    asm volatile(".long 0x7C842379\n.long 0x41800028\n.long 0x8163004C\n.long 0x3D20BA2E\n.long 0x80030050\n.long 0x61298BA3\n.long 0x7C0B0050\n.long 0x7C0049D6\n.long 0x7C001670\n.long 0x7C040040\n.long 0x4180000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x1C64002C\n.long 0x7C6B1A14\n.long 0x4E800020");
}
