// 0x801ACF0C (104 bytes)
// E2ETarget::InitializeEyeToy(void)

class E2ETarget { public: void InitializeEyeToy(void); };

__attribute__((naked))
void E2ETarget::InitializeEyeToy(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x3BE00000\n.long 0x4BE8BDCD\n.long 0x2C030000\n.long 0x41820020\n.long 0x3C60801B\n.long 0x3863CC34\n.long 0x4BE8B5A9\n.long 0x4BE8C00D\n.long 0x93FE008C\n.long 0x3BE00001\n.long 0x48000014\n.long 0x38600000\n.long 0x4BE8B591\n.long 0x38000001\n.long 0x901E008C\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
