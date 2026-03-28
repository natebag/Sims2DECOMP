// 0x800A64F8 (76 bytes)
// GetNextRandomNumber(void)

__attribute__((naked))
void GetNextRandomNumber(void) {
    asm volatile(".long 0x812D9FF8\n.long 0x3C0041C6\n.long 0x60004E6D\n.long 0x552B043E\n.long 0x552A843E\n.long 0x1C6B4E6D\n.long 0x7D2901D6\n.long 0x1C0A41C6\n.long 0x38633039\n.long 0x5463843E\n.long 0x1D6B41C6\n.long 0x39293039\n.long 0x912D9FF8\n.long 0x1D4A4E6D\n.long 0x5400801E\n.long 0x7C635A14\n.long 0x7C635214\n.long 0x7C630214\n.long 0x4E800020");
}
