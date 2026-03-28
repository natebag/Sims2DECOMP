// 0x801A2B3C (104 bytes)
// ACTTarget::GetRecord(void)

class ACTTarget { public: void GetRecord(void); };

__attribute__((naked))
void ACTTarget::GetRecord(void) {
    asm volatile(".long 0x7C681B78\n.long 0x39400000\n.long 0x38600000\n.long 0x396800F0\n.long 0x800B0000\n.long 0x2C000000\n.long 0x4082000C\n.long 0x39400001\n.long 0x4800000C\n.long 0x396B004C\n.long 0x38630001\n.long 0x2F830011\n.long 0x69490001\n.long 0x4FFEE382\n.long 0x7C000026\n.long 0x540007FE\n.long 0x7C074839\n.long 0x4082FFCC\n.long 0x2C0A0000\n.long 0x41820014\n.long 0x1C63004C\n.long 0x386300EC\n.long 0x7C681A14\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
