// 0x801C8794 (88 bytes)
// MMUTarget::Dialog2ClosedCallback(void)

class MMUTarget { public: void Dialog2ClosedCallback(void); };

__attribute__((naked))
void MMUTarget::Dialog2ClosedCallback(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x38800001\n.long 0x806D9864\n.long 0x4815AE31\n.long 0x7C631B79\n.long 0x41820010\n.long 0x7FE3FB78\n.long 0x4BFFE931\n.long 0x4800000C\n.long 0x3D208047\n.long 0x9069E698\n.long 0x38000000\n.long 0x901F0190\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
