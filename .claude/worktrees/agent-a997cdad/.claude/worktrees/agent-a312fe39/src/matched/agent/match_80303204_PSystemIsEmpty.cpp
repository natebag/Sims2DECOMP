// 0x80303204 (68 bytes)
// PSystemIsEmpty

__attribute__((naked))
void PSystemIsEmpty() {
    asm volatile(".long 0x7C631B79\n.long 0x4D820020\n.long 0x81230000\n.long 0x80090088\n.long 0x90090090\n.long 0x4800000C\n.long 0x80090000\n.long 0x900B0090\n.long 0x81630000\n.long 0x38000000\n.long 0x812B0090\n.long 0x2C090000\n.long 0x41820008\n.long 0x80090008\n.long 0x2C000000\n.long 0x4082FFDC\n.long 0x4E800020");
}
