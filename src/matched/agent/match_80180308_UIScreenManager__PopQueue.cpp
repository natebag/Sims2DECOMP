// 0x80180308 (64 bytes)
// UIScreenManager::PopQueue(int)

class UIScreenManager { public: void PopQueue(int); };

__attribute__((naked))
void UIScreenManager::PopQueue(int) {
    asm volatile(".long 0x2C040007\n.long 0x41810030\n.long 0x5489103A\n.long 0x39290200\n.long 0x7D291A14\n.long 0x2C040000\n.long 0x4081000C\n.long 0x80090004\n.long 0x90090000\n.long 0x38840001\n.long 0x39290004\n.long 0x2C040007\n.long 0x4081FFE4\n.long 0x38000000\n.long 0x90030220\n.long 0x4E800020");
}
