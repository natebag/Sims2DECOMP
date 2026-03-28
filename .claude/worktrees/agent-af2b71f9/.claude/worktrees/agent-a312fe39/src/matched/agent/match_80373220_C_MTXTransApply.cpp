// 0x80373220 (120 bytes)
// C_MTXTransApply

__attribute__((naked))
void C_MTXTransApply() {
    asm volatile(".long 0x7C032040\n.long 0x4182004C\n.long 0xC0030000\n.long 0xD0040000\n.long 0xC0030004\n.long 0xD0040004\n.long 0xC0030008\n.long 0xD0040008\n.long 0xC0030010\n.long 0xD0040010\n.long 0xC0030014\n.long 0xD0040014\n.long 0xC0030018\n.long 0xD0040018\n.long 0xC0030020\n.long 0xD0040020\n.long 0xC0030024\n.long 0xD0040024\n.long 0xC0030028\n.long 0xD0040028\n.long 0xC003000C\n.long 0xEC00082A\n.long 0xD004000C\n.long 0xC003001C\n.long 0xEC00102A\n.long 0xD004001C\n.long 0xC003002C\n.long 0xEC00182A\n.long 0xD004002C\n.long 0x4E800020");
}
