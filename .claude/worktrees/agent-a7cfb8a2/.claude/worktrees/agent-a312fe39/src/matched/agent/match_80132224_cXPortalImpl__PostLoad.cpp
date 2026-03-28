// 0x80132224 (72 bytes)
// cXPortalImpl::PostLoad(int, bool)

class cXPortalImpl { public: void PostLoad(int, bool); };

__attribute__((naked))
void cXPortalImpl::PostLoad(int, bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x807F0000\n.long 0x4BF94B6D\n.long 0x2C1E0033\n.long 0x41810010\n.long 0x7FE3FB78\n.long 0x38800001\n.long 0x4BFFDBC9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
