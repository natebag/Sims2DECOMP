// 0x800B3CB4 (64 bytes)
// GetComeSeeMeSelector(void)

__attribute__((naked))
void GetComeSeeMeSelector(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x806DABFC\n.long 0x3C80F3AA\n.long 0x6084A62F\n.long 0x81230000\n.long 0xA8090078\n.long 0x8129007C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
