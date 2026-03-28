// 0x80162298 (92 bytes)
// CasMediator::IsTransitionComplete(void)

class CasMediator { public: void IsTransitionComplete(void); };

__attribute__((naked))
void CasMediator::IsTransitionComplete(void) {
    asm volatile(".long 0x80030014\n.long 0x2C000000\n.long 0x41820010\n.long 0x80630018\n.long 0x2C030000\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x3D20803E\n.long 0xC1A30AA8\n.long 0xC009F2FC\n.long 0x38000000\n.long 0xFC0D0000\n.long 0x40800020\n.long 0x3D20803E\n.long 0xC1A30AAC\n.long 0xC009F300\n.long 0xFC0D0000\n.long 0x4C620382\n.long 0x40830008\n.long 0x38000001\n.long 0x68030001\n.long 0x4E800020");
}
