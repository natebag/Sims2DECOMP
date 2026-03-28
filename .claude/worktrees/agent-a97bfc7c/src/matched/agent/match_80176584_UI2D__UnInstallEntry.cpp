// 0x80176584 (68 bytes)
// UI2D::UnInstallEntry(char *)

class UI2D { public: void UnInstallEntry(char *); };

__attribute__((naked))
void UI2D::UnInstallEntry(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BFFFF35\n.long 0x7C641B79\n.long 0x38600000\n.long 0x41820010\n.long 0x7FE3FB78\n.long 0x4BFFFCC9\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
