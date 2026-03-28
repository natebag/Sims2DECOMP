// 0x8017FEF8 (76 bytes)
// UIScreenManager::RemoveScreen(UIScreenID)

class UIScreenManager { public: void RemoveScreen(UIScreenID); };

__attribute__((naked))
void UIScreenManager::RemoveScreen(UIScreenID) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x3BE00000\n.long 0x4BFFFFA9\n.long 0x2C03FFFF\n.long 0x41820014\n.long 0x54602036\n.long 0x393E0088\n.long 0x7FE9012E\n.long 0x3BE00001\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
