// 0x8036594C (128 bytes)
// PoolFree

__attribute__((naked))
void PoolFree() {
    asm volatile(".long 0x7C6B1B78\n.long 0x3944FFF0\n.long 0x800B0008\n.long 0x2C000000\n.long 0x4082000C\n.long 0x3860FFFF\n.long 0x4E800020\n.long 0x800B0010\n.long 0x7C0A0000\n.long 0x4082000C\n.long 0x8004FFF0\n.long 0x900B0010\n.long 0x812A0004\n.long 0x2C090000\n.long 0x4182000C\n.long 0x8004FFF0\n.long 0x90090000\n.long 0x8124FFF0\n.long 0x2C090000\n.long 0x4182000C\n.long 0x800A0004\n.long 0x90090004\n.long 0x39200000\n.long 0x38600000\n.long 0x912A0004\n.long 0x800B000C\n.long 0x9004FFF0\n.long 0x914B000C\n.long 0x812B0008\n.long 0x3929FFFF\n.long 0x912B0008\n.long 0x4E800020");
}
