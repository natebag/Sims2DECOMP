// 0x8039AD24 (64 bytes)
// _restfpr_20_x

__attribute__((naked))
void _restfpr_20_x() {
    asm volatile(".long 0xCA8BFFA0\n.long 0xCAABFFA8\n.long 0xCACBFFB0\n.long 0xCAEBFFB8\n.long 0xCB0BFFC0\n.long 0xCB2BFFC8\n.long 0xCB4BFFD0\n.long 0xCB6BFFD8\n.long 0xCB8BFFE0\n.long 0xCBABFFE8\n.long 0xCBCBFFF0\n.long 0x800B0004\n.long 0xCBEBFFF8\n.long 0x7C0803A6\n.long 0x7D615B78\n.long 0x4E800020");
}
