// 0x8039ABE8 (64 bytes)
// _savefpr_17

__attribute__((naked))
void _savefpr_17() {
    asm volatile(".long 0xDA2BFF88\n.long 0xDA4BFF90\n.long 0xDA6BFF98\n.long 0xDA8BFFA0\n.long 0xDAABFFA8\n.long 0xDACBFFB0\n.long 0xDAEBFFB8\n.long 0xDB0BFFC0\n.long 0xDB2BFFC8\n.long 0xDB4BFFD0\n.long 0xDB6BFFD8\n.long 0xDB8BFFE0\n.long 0xDBABFFE8\n.long 0xDBCBFFF0\n.long 0xDBEBFFF8\n.long 0x4E800020");
}
