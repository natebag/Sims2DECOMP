// 0x801EC0D0 (68 bytes)
// StaticConvertTabToCategory(int)

__attribute__((naked))
void StaticConvertTabToCategory(int) {
    asm volatile(".long 0x2C030001\n.long 0x41820028\n.long 0x41810010\n.long 0x2C030000\n.long 0x41820014\n.long 0x48000028\n.long 0x2C030002\n.long 0x41820018\n.long 0x4800001C\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600003\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
