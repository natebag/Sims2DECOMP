// 0x800B42BC (120 bytes)
// GlobalDispatch(short, int)

__attribute__((naked))
void GlobalDispatch(short, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x816D82B4\n.long 0x7C7C1B78\n.long 0x7C9D2378\n.long 0x3BC00000\n.long 0x2C0B0000\n.long 0x4182003C\n.long 0x812B000C\n.long 0x7F84E378\n.long 0x7FA5EB78\n.long 0x83EB0000\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x41820008\n.long 0x3BC00001\n.long 0x7FEBFB79\n.long 0x4082FFCC\n.long 0x7FC3F378\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
