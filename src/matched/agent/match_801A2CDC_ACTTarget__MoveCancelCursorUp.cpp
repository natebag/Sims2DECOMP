// 0x801A2CDC (84 bytes)
// ACTTarget::MoveCancelCursorUp(void)

class ACTTarget { public: void MoveCancelCursorUp(void); };

__attribute__((naked))
void ACTTarget::MoveCancelCursorUp(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6A1B78\n.long 0x812A0648\n.long 0x2C090000\n.long 0x4182002C\n.long 0x81690044\n.long 0x2C0B0000\n.long 0x41820020\n.long 0x800B0000\n.long 0x2C000008\n.long 0x41810014\n.long 0x912A064C\n.long 0x80090044\n.long 0x900A0648\n.long 0x4800027D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
