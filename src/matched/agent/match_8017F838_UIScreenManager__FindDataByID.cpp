// 0x8017F838 (68 bytes)
// UIScreenManager::FindDataByID(UIScreenID)

class UIScreenManager { public: void FindDataByID(UIScreenID); };

__attribute__((naked))
void UIScreenManager::FindDataByID(UIScreenID) {
    asm volatile(".long 0x3D208042\n.long 0x38600000\n.long 0x39294720\n.long 0x39600000\n.long 0x7D2A4B78\n.long 0x7C0B482E\n.long 0x7C002000\n.long 0x40820008\n.long 0x7D435378\n.long 0x394A0018\n.long 0x396B0018\n.long 0x2C030000\n.long 0x4C820020\n.long 0x7C0B482E\n.long 0x2C000045\n.long 0x4082FFD8\n.long 0x4E800020");
}
