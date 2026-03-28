// 0x8019A424 (100 bytes)
// CASSelectionTarget::SetupInitialSelectionPage(void)

class CASSelectionTarget { public: void SetupInitialSelectionPage(void); };

__attribute__((naked))
void CASSelectionTarget::SetupInitialSelectionPage(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x38000001\n.long 0x901F0548\n.long 0x48000049\n.long 0x80BF008C\n.long 0x2C050000\n.long 0x40810020\n.long 0x38A50004\n.long 0x2C05000F\n.long 0x40810008\n.long 0x38A0000F\n.long 0x7FE3FB78\n.long 0x38800004\n.long 0x4BFFFD99\n.long 0x7FE3FB78\n.long 0x48000185\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
