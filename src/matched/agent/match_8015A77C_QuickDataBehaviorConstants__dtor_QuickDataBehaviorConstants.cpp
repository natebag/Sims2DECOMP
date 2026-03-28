// 0x8015A77C (80 bytes)
// QuickDataBehaviorConstants::~QuickDataBehaviorConstants(void)

class QuickDataBehaviorConstants { public: void ~QuickDataBehaviorConstants(void); };

__attribute__((naked))
void QuickDataBehaviorConstants::~QuickDataBehaviorConstants(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208046\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x392956D0\n.long 0x913F0000\n.long 0x38800000\n.long 0x4BFFF3B9\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFFF69D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
