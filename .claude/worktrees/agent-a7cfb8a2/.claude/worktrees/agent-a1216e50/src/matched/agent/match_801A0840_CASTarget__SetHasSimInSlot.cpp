// 0x801A0840 (80 bytes)
// CASTarget::SetHasSimInSlot(int, bool)

class CASTarget { public: void SetHasSimInSlot(int, bool); };

__attribute__((naked))
void CASTarget::SetHasSimInSlot(int, bool) {
    asm volatile(".long 0x7C802378\n.long 0x2C040000\n.long 0x40800008\n.long 0x38040003\n.long 0x5400003A\n.long 0x2C050000\n.long 0x7C802050\n.long 0x4182001C\n.long 0x81231348\n.long 0x38000001\n.long 0x7C002030\n.long 0x7D290378\n.long 0x91231348\n.long 0x4E800020\n.long 0x81231348\n.long 0x3800FFFE\n.long 0x5C00203E\n.long 0x7D290038\n.long 0x91231348\n.long 0x4E800020");
}
