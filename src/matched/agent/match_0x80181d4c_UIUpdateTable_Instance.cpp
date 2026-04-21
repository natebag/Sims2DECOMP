// 0x80181d4c (60B) UIUpdateTable::Instance(void)

struct UIUpdateTable {
    char data[16];
    UIUpdateTable();
    static UIUpdateTable* Instance();
};

extern UIUpdateTable* g_UIUpdateTable_instance;

UIUpdateTable* UIUpdateTable::Instance() {
    if (!g_UIUpdateTable_instance) {
        g_UIUpdateTable_instance = new UIUpdateTable();
    }
    return g_UIUpdateTable_instance;
}
