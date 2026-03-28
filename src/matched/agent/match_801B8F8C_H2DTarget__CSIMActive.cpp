// 0x801B8F8C (76 bytes)
// H2DTarget::CSIMActive(int, bool)

class H2DTarget { public: void CSIMActive(int, bool); };

__attribute__((naked))
void H2DTarget::CSIMActive(int, bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x5484103A\n.long 0x38630088\n.long 0x7C63202E\n.long 0x2C030000\n.long 0x41820020\n.long 0x2C050000\n.long 0x41820010\n.long 0x38800001\n.long 0x48011691\n.long 0x4800000C\n.long 0x38800004\n.long 0x48011685\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
