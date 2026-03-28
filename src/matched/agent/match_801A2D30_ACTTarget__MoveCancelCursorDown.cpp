// 0x801A2D30 (72 bytes)
// ACTTarget::MoveCancelCursorDown(void)

class ACTTarget { public: void MoveCancelCursorDown(void); };

__attribute__((naked))
void ACTTarget::MoveCancelCursorDown(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x812B0648\n.long 0x2C090000\n.long 0x41820020\n.long 0x80090048\n.long 0x2C000000\n.long 0x41820014\n.long 0x912B064C\n.long 0x80090048\n.long 0x900B0648\n.long 0x48000235\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
