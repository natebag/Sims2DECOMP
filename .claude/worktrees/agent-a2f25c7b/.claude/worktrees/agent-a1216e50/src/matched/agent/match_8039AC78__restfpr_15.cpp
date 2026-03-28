// 0x8039AC78 (72 bytes)
// _restfpr_15

__attribute__((naked))
void _restfpr_15() {
    asm volatile(".long 0xC9EBFF78\n.long 0xCA0BFF80\n.long 0xCA2BFF88\n.long 0xCA4BFF90\n.long 0xCA6BFF98\n.long 0xCA8BFFA0\n.long 0xCAABFFA8\n.long 0xCACBFFB0\n.long 0xCAEBFFB8\n.long 0xCB0BFFC0\n.long 0xCB2BFFC8\n.long 0xCB4BFFD0\n.long 0xCB6BFFD8\n.long 0xCB8BFFE0\n.long 0xCBABFFE8\n.long 0xCBCBFFF0\n.long 0xCBEBFFF8\n.long 0x4E800020");
}
