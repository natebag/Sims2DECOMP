// 0x801C6DF0 (108 bytes)
// MMUTarget::LaunchFreeplay(void)

class MMUTarget { public: void LaunchFreeplay(void); };

__attribute__((naked))
void MMUTarget::LaunchFreeplay(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208047\n.long 0x38000001\n.long 0x39295B84\n.long 0x7C7E1B78\n.long 0x7D234B78\n.long 0x900900E4\n.long 0x90090084\n.long 0x38800000\n.long 0x4BE76319\n.long 0x3C60803F\n.long 0x38632D3C\n.long 0x4BFB0EE1\n.long 0x38000000\n.long 0x7FC3F378\n.long 0x901E008C\n.long 0x4BFFF961\n.long 0x7FC3F378\n.long 0x4BFFFAA5\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
