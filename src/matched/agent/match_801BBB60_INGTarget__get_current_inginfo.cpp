// 0x801BBB60 (72 bytes)
// INGTarget::get_current_inginfo(void)

class INGTarget { public: void get_current_inginfo(void); };

__attribute__((naked))
void INGTarget::get_current_inginfo(void) {
    asm volatile(".long 0x8003044C\n.long 0x2800000B\n.long 0x4081000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x5400103A\n.long 0x392301B0\n.long 0x7D29002E\n.long 0x2C090000\n.long 0x4182001C\n.long 0x80090000\n.long 0x38600000\n.long 0x2C000000\n.long 0x4D820020\n.long 0x7D234B78\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
