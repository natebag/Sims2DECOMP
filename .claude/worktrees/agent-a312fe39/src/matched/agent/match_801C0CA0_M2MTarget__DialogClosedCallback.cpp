// 0x801C0CA0 (104 bytes)
// M2MTarget::DialogClosedCallback(void)

class M2MTarget { public: void DialogClosedCallback(void); };

__attribute__((naked))
void M2MTarget::DialogClosedCallback(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F011C\n.long 0x2C000001\n.long 0x41820030\n.long 0x2C000005\n.long 0x40820030\n.long 0x3C60803F\n.long 0x38800007\n.long 0x386320DC\n.long 0x4BFB8EDD\n.long 0x7FE3FB78\n.long 0x480014FD\n.long 0x38000003\n.long 0x901F0168\n.long 0x4800000C\n.long 0x7FE3FB78\n.long 0x480010F1\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
