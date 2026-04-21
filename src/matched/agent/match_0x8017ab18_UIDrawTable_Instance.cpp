// 0x8017ab18 (60B) UIDrawTable::Instance(void)

struct UIDrawTable {
    char data[16];
    UIDrawTable();
    static UIDrawTable* Instance();
};

extern UIDrawTable* g_UIDrawTable_instance;

UIDrawTable* UIDrawTable::Instance() {
    if (!g_UIDrawTable_instance) {
        g_UIDrawTable_instance = new UIDrawTable();
    }
    return g_UIDrawTable_instance;
}
