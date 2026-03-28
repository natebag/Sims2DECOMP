// 0x8017D254 (92 bytes)
// UIReflow::~UIReflow(void)

class UIReflow { public: void ~UIReflow(void); };

__attribute__((naked))
void UIReflow::~UIReflow(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x801F0000\n.long 0x2C000000\n.long 0x41820018\n.long 0x48152C89\n.long 0x809F0000\n.long 0x48153AF9\n.long 0x38000000\n.long 0x901F0000\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x48153F89\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
