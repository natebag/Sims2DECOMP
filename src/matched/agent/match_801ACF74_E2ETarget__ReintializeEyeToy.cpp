// 0x801ACF74 (84 bytes)
// E2ETarget::ReintializeEyeToy(void)

class E2ETarget { public: void ReintializeEyeToy(void); };

__attribute__((naked))
void E2ETarget::ReintializeEyeToy(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x38600000\n.long 0x4BE8B555\n.long 0x4BE8BFED\n.long 0x4BE8BE31\n.long 0x7FE3FB78\n.long 0x4BFFFF71\n.long 0x801F008C\n.long 0x2C000000\n.long 0x4082000C\n.long 0x387F00E4\n.long 0x4800A259\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
