// 0x801D6218 (124 bytes)
// PCTTarget::can_afford_selection(void) const

class PCTTarget { public: void can_afford_selection(void) const; };

__attribute__((naked))
void PCTTarget::can_afford_selection(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x808300B8\n.long 0x4BFFE7B5\n.long 0x7C7F1B79\n.long 0x38600000\n.long 0x41820048\n.long 0x4BE6C5E1\n.long 0x7C7E1B78\n.long 0x7FE3FB78\n.long 0x4BFFBEF9\n.long 0x801F000C\n.long 0x7F83F000\n.long 0x4FFEE382\n.long 0x7C600026\n.long 0x546307FE\n.long 0x2C000000\n.long 0x41820008\n.long 0x38600000\n.long 0x3D208047\n.long 0x80096188\n.long 0x2C000000\n.long 0x41820008\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
