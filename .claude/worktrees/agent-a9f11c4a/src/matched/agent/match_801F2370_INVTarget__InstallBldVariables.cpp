// 0x801F2370 (64 bytes)
// INVTarget::InstallBldVariables(void)

class INVTarget { public: void InstallBldVariables(void); };

__attribute__((naked))
void INVTarget::InstallBldVariables(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C651B78\n.long 0x3D208040\n.long 0x80050000\n.long 0x388997C8\n.long 0x2C000000\n.long 0x41820010\n.long 0x80650004\n.long 0x38A50028\n.long 0x4BF85C41\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
