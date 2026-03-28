// 0x8017FEB8 (64 bytes)
// UIScreenManager::FindRecordIndexByID(UIScreenID)

class UIScreenManager { public: void FindRecordIndexByID(UIScreenID); };

__attribute__((naked))
void UIScreenManager::FindRecordIndexByID(UIScreenID) {
    asm volatile(".long 0x38000018\n.long 0x38630074\n.long 0x7C0903A6\n.long 0x3920FFFF\n.long 0x39600000\n.long 0x84030010\n.long 0x39290001\n.long 0x7C002000\n.long 0x40820008\n.long 0x39600001\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x4200FFE4\n.long 0x3920FFFF\n.long 0x7D234B78\n.long 0x4E800020");
}
