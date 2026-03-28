// 0x80180068 (84 bytes)
// UIScreenManager::IsUIScreenMarkedForUnloading(UIScreenID)

class UIScreenManager { public: void IsUIScreenMarkedForUnloading(UIScreenID); };

__attribute__((naked))
void UIScreenManager::IsUIScreenMarkedForUnloading(UIScreenID) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3BC00000\n.long 0x4BFFFE39\n.long 0x2C03FFFF\n.long 0x4082001C\n.long 0x353F0074\n.long 0x41820014\n.long 0x80090004\n.long 0x681E0003\n.long 0x213E0000\n.long 0x7FC9F114\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
