// 0x8017E920 (120 bytes)
// UIReflow::OpenReflowBlock(void)

class UIReflow { public: void OpenReflowBlock(void); };

__attribute__((naked))
void UIReflow::OpenReflowBlock(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x83DF0000\n.long 0x2C1E0000\n.long 0x40820048\n.long 0x38000001\n.long 0x39201000\n.long 0x901F0008\n.long 0x913F000C\n.long 0x481515B1\n.long 0x809F000C\n.long 0x38A00000\n.long 0x48152149\n.long 0x93DF0010\n.long 0x2C030000\n.long 0x907F0000\n.long 0x907F0004\n.long 0x41820014\n.long 0x3C80803E\n.long 0x7FE3FB78\n.long 0x3884375C\n.long 0x4BFFF6A9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
