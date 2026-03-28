// 0x80371F9C (108 bytes)
// C_MTXCopy

__attribute__((naked))
void C_MTXCopy() {
    asm volatile(".long 0x7C032040\n.long 0x4D820020\n.long 0xC0030000\n.long 0xD0040000\n.long 0xC0030004\n.long 0xD0040004\n.long 0xC0030008\n.long 0xD0040008\n.long 0xC003000C\n.long 0xD004000C\n.long 0xC0030010\n.long 0xD0040010\n.long 0xC0030014\n.long 0xD0040014\n.long 0xC0030018\n.long 0xD0040018\n.long 0xC003001C\n.long 0xD004001C\n.long 0xC0030020\n.long 0xD0040020\n.long 0xC0030024\n.long 0xD0040024\n.long 0xC0030028\n.long 0xD0040028\n.long 0xC003002C\n.long 0xD004002C\n.long 0x4E800020");
}
