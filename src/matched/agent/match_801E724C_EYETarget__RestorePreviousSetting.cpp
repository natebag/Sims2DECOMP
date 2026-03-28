// 0x801E724C (64 bytes)
// EYETarget::RestorePreviousSetting(void)

class EYETarget { public: void RestorePreviousSetting(void); };

__attribute__((naked))
void EYETarget::RestorePreviousSetting(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800300A8\n.long 0x2C000000\n.long 0x4182001C\n.long 0x81230088\n.long 0x7C0803A6\n.long 0xC02300A4\n.long 0x3929FFFF\n.long 0x91230088\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
