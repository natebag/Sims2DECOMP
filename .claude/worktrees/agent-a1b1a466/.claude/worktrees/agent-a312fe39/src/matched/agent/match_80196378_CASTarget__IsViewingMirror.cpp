// 0x80196378 (84 bytes)
// CASTarget::IsViewingMirror(void)

class CASTarget { public: void IsViewingMirror(void); };

__attribute__((naked))
void CASTarget::IsViewingMirror(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030104\n.long 0x2C000003\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000028\n.long 0x81230084\n.long 0x8069001C\n.long 0x4BFFE089\n.long 0x2C030008\n.long 0x41810010\n.long 0x2C030002\n.long 0x38600000\n.long 0x40800008\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
