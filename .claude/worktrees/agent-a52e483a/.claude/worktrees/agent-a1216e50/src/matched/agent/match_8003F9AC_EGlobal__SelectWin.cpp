// 0x8003F9AC (80 bytes)
// EGlobal::SelectWin(ERC *)

class EGlobal { public: void SelectWin(ERC *); };

__attribute__((naked))
void EGlobal::SelectWin(ERC *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800300D0\n.long 0x2C000000\n.long 0x4182002C\n.long 0x35600010\n.long 0x41820024\n.long 0x2C040000\n.long 0x4182001C\n.long 0x812B009C\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
