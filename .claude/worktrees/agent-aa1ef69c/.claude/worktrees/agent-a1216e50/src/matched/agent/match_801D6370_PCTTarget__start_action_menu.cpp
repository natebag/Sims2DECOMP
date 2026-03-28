// 0x801D6370 (72 bytes)
// PCTTarget::start_action_menu(void)

class PCTTarget { public: void start_action_menu(void); };

__attribute__((naked))
void PCTTarget::start_action_menu(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800300E4\n.long 0x2C000000\n.long 0x41820020\n.long 0x3D208047\n.long 0x80A30084\n.long 0x80895BC8\n.long 0x7C030378\n.long 0x4BFAD065\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
