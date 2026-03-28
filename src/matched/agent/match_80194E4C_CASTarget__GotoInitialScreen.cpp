// 0x80194E4C (112 bytes)
// CASTarget::GotoInitialScreen(void)

class CASTarget { public: void GotoInitialScreen(void); };

__attribute__((naked))
void CASTarget::GotoInitialScreen(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030104\n.long 0x2C000002\n.long 0x41820044\n.long 0x41810018\n.long 0x2C000000\n.long 0x41820038\n.long 0x2C000001\n.long 0x41820028\n.long 0x4800002C\n.long 0x2C000004\n.long 0x41820024\n.long 0x41800010\n.long 0x2C000005\n.long 0x41820010\n.long 0x48000014\n.long 0x38800018\n.long 0x48000010\n.long 0x3880000A\n.long 0x48000008\n.long 0x38800003\n.long 0x4BFFFEFD\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
