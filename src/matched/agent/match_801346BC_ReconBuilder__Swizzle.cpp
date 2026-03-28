// 0x801346BC (64 bytes)
// ReconBuilder::Swizzle(void *, int)

class ReconBuilder { public: void Swizzle(void *, int); };

__attribute__((naked))
void ReconBuilder::Swizzle(void *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000001\n.long 0x387E0004\n.long 0x981E0000\n.long 0x4BF73731\n.long 0x387E0008\n.long 0x4BF73729\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
