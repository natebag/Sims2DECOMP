// 0x8017D2B0 (112 bytes)
// UIReflow::SetFocus(UIScreenID)

class UIReflow { public: void SetFocus(UIScreenID); };

__attribute__((naked))
void UIReflow::SetFocus(UIScreenID) {
    asm volatile(".long 0x9421FF78\n.long 0x7C0802A6\n.long 0x9001008C\n.long 0x80030004\n.long 0x2C000000\n.long 0x4082004C\n.long 0x3D208047\n.long 0x7C852378\n.long 0x80695F10\n.long 0x38810008\n.long 0x48002C6D\n.long 0x2C030000\n.long 0x41820030\n.long 0x3C80803E\n.long 0x3D00803E\n.long 0x806D9DD0\n.long 0x38843748\n.long 0x39083750\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00002\n.long 0x39210008\n.long 0x4CC63182\n.long 0x4BE93089\n.long 0x8001008C\n.long 0x7C0803A6\n.long 0x38210088\n.long 0x4E800020");
}
