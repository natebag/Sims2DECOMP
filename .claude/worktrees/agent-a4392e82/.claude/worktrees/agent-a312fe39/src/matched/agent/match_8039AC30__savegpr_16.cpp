// 0x8039AC30 (68 bytes)
// _savegpr_16

__attribute__((naked))
void _savegpr_16() {
    asm volatile(".long 0x920BFFC0\n.long 0x922BFFC4\n.long 0x924BFFC8\n.long 0x926BFFCC\n.long 0x928BFFD0\n.long 0x92ABFFD4\n.long 0x92CBFFD8\n.long 0x92EBFFDC\n.long 0x930BFFE0\n.long 0x932BFFE4\n.long 0x934BFFE8\n.long 0x936BFFEC\n.long 0x938BFFF0\n.long 0x93ABFFF4\n.long 0x93CBFFF8\n.long 0x93EBFFFC\n.long 0x4E800020");
}
