// 0x801B8C98 (116 bytes)
// H2DTarget::ACTCancelModeExited(int)

class H2DTarget { public: void ACTCancelModeExited(int); };

__attribute__((naked))
void H2DTarget::ACTCancelModeExited(int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x549F103A\n.long 0x393E0104\n.long 0x7C09F82E\n.long 0x2C000000\n.long 0x4182003C\n.long 0x3B800000\n.long 0x3BBE010C\n.long 0x7F89F92E\n.long 0x7CBDF82E\n.long 0x2C050000\n.long 0x41820024\n.long 0x3D208047\n.long 0x80695E80\n.long 0x4BE58E6D\n.long 0x7F9DF92E\n.long 0x393E0088\n.long 0x38800004\n.long 0x7C69F82E\n.long 0x48011955\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
