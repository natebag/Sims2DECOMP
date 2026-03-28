// 0x80042874 (92 bytes)
// SetSimFunds(unsigned int, int)

__attribute__((naked))
void SetSimFunds(unsigned int, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DAC08\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000030\n.long 0x2C030000\n.long 0x38A00001\n.long 0x40820008\n.long 0x38A00000\n.long 0x812B0000\n.long 0xA86900D0\n.long 0x800900D4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
