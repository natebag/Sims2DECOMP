// 0x8017FE64 (84 bytes)
// UIScreenManager::AddScreen(UIScreenID, int)

class UIScreenManager { public: void AddScreen(UIScreenID, int); };

__attribute__((naked))
void UIScreenManager::AddScreen(UIScreenID, int) {
    asm volatile(".long 0x38000018\n.long 0x38630084\n.long 0x7C0903A6\n.long 0x39600000\n.long 0x39200000\n.long 0x80030004\n.long 0x2C000000\n.long 0x40820008\n.long 0x7C691B78\n.long 0x38630010\n.long 0x2C090000\n.long 0x4082000C\n.long 0x4200FFE4\n.long 0x48000018\n.long 0x38000001\n.long 0x90890000\n.long 0x90090004\n.long 0x39600001\n.long 0x90A9000C\n.long 0x7D635B78\n.long 0x4E800020");
}
