// 0x8039AD6C (80 bytes)
// _restgpr_16_x

__attribute__((naked))
void _restgpr_16_x() {
    asm volatile(".long 0x820BFFC0\n.long 0x822BFFC4\n.long 0x824BFFC8\n.long 0x826BFFCC\n.long 0x828BFFD0\n.long 0x82ABFFD4\n.long 0x82CBFFD8\n.long 0x82EBFFDC\n.long 0x830BFFE0\n.long 0x832BFFE4\n.long 0x834BFFE8\n.long 0x836BFFEC\n.long 0x838BFFF0\n.long 0x83ABFFF4\n.long 0x83CBFFF8\n.long 0x800B0004\n.long 0x83EBFFFC\n.long 0x7C0803A6\n.long 0x7D615B78\n.long 0x4E800020");
}
