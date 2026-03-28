// 0x8017EBB0 (120 bytes)
// UIReflow::Reflow_Visibility(bool)

class UIReflow { public: void Reflow_Visibility(bool); };

__attribute__((naked))
void UIReflow::Reflow_Visibility(bool) {
    asm volatile(".long 0x9421FF70\n.long 0x7C0802A6\n.long 0xBFC10088\n.long 0x90010094\n.long 0x7C9E2378\n.long 0x7C7F1B78\n.long 0x3C80803E\n.long 0x388437D4\n.long 0x4BFFF459\n.long 0x2C1E0000\n.long 0x38A00000\n.long 0x41820008\n.long 0x38A00001\n.long 0x3C80803E\n.long 0x38610008\n.long 0x38843784\n.long 0x4CC63182\n.long 0x4815FC95\n.long 0x38810008\n.long 0x7FE3FB78\n.long 0x4BFFF429\n.long 0x3C80803E\n.long 0x7FE3FB78\n.long 0x388437DC\n.long 0x4BFFF419\n.long 0x80010094\n.long 0x7C0803A6\n.long 0xBBC10088\n.long 0x38210090\n.long 0x4E800020");
}
