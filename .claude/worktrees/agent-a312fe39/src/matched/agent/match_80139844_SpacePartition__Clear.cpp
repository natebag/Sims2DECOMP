// 0x80139844 (120 bytes)
// SpacePartition::Clear(void)

class SpacePartition { public: void Clear(void); };

__attribute__((naked))
void SpacePartition::Clear(void) {
    asm volatile(".long 0x8163000C\n.long 0x3943000C\n.long 0x800A0004\n.long 0x7D695B78\n.long 0x3903004C\n.long 0x38E3001C\n.long 0x7C0B0000\n.long 0x38C3002C\n.long 0x38A3003C\n.long 0x41820010\n.long 0x39290014\n.long 0x7C090000\n.long 0x4082FFF8\n.long 0x916A0004\n.long 0x8163004C\n.long 0x80080004\n.long 0x7D695B78\n.long 0x7C0B0000\n.long 0x41820010\n.long 0x3929002C\n.long 0x7C090000\n.long 0x4082FFF8\n.long 0x91680004\n.long 0x8003001C\n.long 0x90070004\n.long 0x8123002C\n.long 0x91260004\n.long 0x8003003C\n.long 0x90050004\n.long 0x4E800020");
}
