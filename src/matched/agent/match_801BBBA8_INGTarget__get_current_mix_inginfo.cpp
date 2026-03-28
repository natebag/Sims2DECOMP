// 0x801BBBA8 (72 bytes)
// INGTarget::get_current_mix_inginfo(void)

class INGTarget { public: void get_current_mix_inginfo(void); };

__attribute__((naked))
void INGTarget::get_current_mix_inginfo(void) {
    asm volatile(".long 0x7C6B1B78\n.long 0x812B0450\n.long 0x28090003\n.long 0x4081000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x55291838\n.long 0x386901E0\n.long 0x7D2B1A15\n.long 0x4182001C\n.long 0x7C0B182E\n.long 0x38600000\n.long 0x2C000000\n.long 0x4D820020\n.long 0x7D234B78\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
