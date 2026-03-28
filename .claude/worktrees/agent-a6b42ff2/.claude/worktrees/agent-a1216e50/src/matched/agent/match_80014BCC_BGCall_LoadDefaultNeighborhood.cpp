// 0x80014BCC (72 bytes)
// BGCall_LoadDefaultNeighborhood(void)

__attribute__((naked))
void BGCall_LoadDefaultNeighborhood(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DA71C\n.long 0x38000000\n.long 0x3C808001\n.long 0x812B0000\n.long 0x38844B9C\n.long 0x900DAC18\n.long 0xA8690040\n.long 0x80090044\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
