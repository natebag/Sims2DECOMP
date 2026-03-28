// 0x8017E408 (108 bytes)
// UIReflow::Tween_Y(int)

class UIReflow { public: void Tween_Y(int); };

__attribute__((naked))
void UIReflow::Tween_Y(int) {
    asm volatile(".long 0x9421FF68\n.long 0x7C0802A6\n.long 0xBFA1008C\n.long 0x9001009C\n.long 0x7C9D2378\n.long 0x7C7E1B78\n.long 0x3C80803E\n.long 0x388437BC\n.long 0x4BFFFC01\n.long 0x3C80803E\n.long 0x7FA5EB78\n.long 0x38843784\n.long 0x38610008\n.long 0x4CC63182\n.long 0x48160449\n.long 0x38810008\n.long 0x7FC3F378\n.long 0x4BFFFBDD\n.long 0x3C80803E\n.long 0x7FC3F378\n.long 0x388437C0\n.long 0x4BFFFBCD\n.long 0x8001009C\n.long 0x7C0803A6\n.long 0xBBA1008C\n.long 0x38210098\n.long 0x4E800020");
}
