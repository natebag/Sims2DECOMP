// 0x803658F0 (92 bytes)
// PoolAlloc

__attribute__((naked))
void PoolAlloc() {
    asm volatile(".long 0x7C6A1B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x816A000C\n.long 0x2C0B0000\n.long 0x4182FFF0\n.long 0x800B0000\n.long 0x39200000\n.long 0x900A000C\n.long 0x912B0004\n.long 0x800A0010\n.long 0x900B0000\n.long 0x812A0010\n.long 0x2C090000\n.long 0x41820008\n.long 0x91690004\n.long 0x812A0008\n.long 0x386B0010\n.long 0x916A0010\n.long 0x39290001\n.long 0x912A0008\n.long 0x4E800020");
}
