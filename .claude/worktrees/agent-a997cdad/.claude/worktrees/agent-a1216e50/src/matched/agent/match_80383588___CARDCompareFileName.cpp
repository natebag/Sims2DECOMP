// 0x80383588 (104 bytes)
// __CARDCompareFileName

__attribute__((naked))
void __CARDCompareFileName() {
    asm volatile(".long 0x38A30008\n.long 0x38E00020\n.long 0x4800003C\n.long 0x88050000\n.long 0x38A50001\n.long 0x88C40000\n.long 0x38840001\n.long 0x7C030774\n.long 0x7CC00774\n.long 0x7C030000\n.long 0x4182000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x7CC00775\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x34E7FFFF\n.long 0x4080FFC4\n.long 0x88040000\n.long 0x7C000775\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
