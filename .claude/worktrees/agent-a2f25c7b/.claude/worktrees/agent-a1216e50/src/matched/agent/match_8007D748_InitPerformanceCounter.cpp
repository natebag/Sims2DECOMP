// 0x8007D748 (84 bytes)
// InitPerformanceCounter(void)

__attribute__((naked))
void InitPerformanceCounter(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800D9FA8\n.long 0x2C000000\n.long 0x40820030\n.long 0x816D985C\n.long 0x3C808048\n.long 0x38845800\n.long 0x812B0000\n.long 0x80090024\n.long 0xA8690020\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000001\n.long 0x900D9FA8\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
