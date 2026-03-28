// 0x8017EEA4 (100 bytes)
// UIRouter::~UIRouter(void)

class UIRouter { public: void ~UIRouter(void); };

__attribute__((naked))
void UIRouter::~UIRouter(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208046\n.long 0x7C7F1B78\n.long 0x39296710\n.long 0x3D608047\n.long 0x913F0080\n.long 0x7C9E2378\n.long 0x7FE4FB78\n.long 0x806B5E80\n.long 0x4BE92F1D\n.long 0x3D208046\n.long 0x73C00001\n.long 0x3929CFD8\n.long 0x913F0080\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x48152331\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
