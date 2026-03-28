// 0x801B0DF8 (116 bytes)
// FAMTarget::IsSelectedLotOccupied(void)

class FAMTarget { public: void IsSelectedLotOccupied(void); };

__attribute__((naked))
void FAMTarget::IsSelectedLotOccupied(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x809F014C\n.long 0x48001BE1\n.long 0x816DAC1C\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690128\n.long 0x8009012C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C641B79\n.long 0x38600000\n.long 0x4182001C\n.long 0x7FE3FB78\n.long 0x4BFFFF71\n.long 0x2C030000\n.long 0x38600001\n.long 0x41810008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
