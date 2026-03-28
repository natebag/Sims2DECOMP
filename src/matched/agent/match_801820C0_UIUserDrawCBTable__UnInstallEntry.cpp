// 0x801820C0 (68 bytes)
// UIUserDrawCBTable::UnInstallEntry(char *)

class UIUserDrawCBTable { public: void UnInstallEntry(char *); };

__attribute__((naked))
void UIUserDrawCBTable::UnInstallEntry(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x480000A1\n.long 0x7C641B79\n.long 0x38600000\n.long 0x41820010\n.long 0x7FE3FB78\n.long 0x4BFFFE99\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
