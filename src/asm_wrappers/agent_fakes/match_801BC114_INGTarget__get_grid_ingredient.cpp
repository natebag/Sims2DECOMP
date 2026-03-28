// 0x801BC114 (64 bytes)
// INGTarget::get_grid_ingredient(short)

class INGTarget { public: void get_grid_ingredient(short); };

__attribute__((naked))
void INGTarget::get_grid_ingredient(short) {
    asm volatile(".long 0x3800000C\n.long 0x396301B0\n.long 0x7C0903A6\n.long 0x806B0000\n.long 0x396B0004\n.long 0x2C030000\n.long 0x4182001C\n.long 0x81230000\n.long 0x2C090000\n.long 0x41820010\n.long 0xA8090000\n.long 0x7C002000\n.long 0x4D820020\n.long 0x4200FFD8\n.long 0x38600000\n.long 0x4E800020");
}
