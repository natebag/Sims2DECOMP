// 0x80182284 (60B) UIUserDrawCBTable::Instance(void)

struct UIUserDrawCBTable {
    char data[16];
    UIUserDrawCBTable();
    static UIUserDrawCBTable* Instance();
};

extern UIUserDrawCBTable* g_UIUserDrawCBTable_instance;

UIUserDrawCBTable* UIUserDrawCBTable::Instance() {
    if (!g_UIUserDrawCBTable_instance) {
        g_UIUserDrawCBTable_instance = new UIUserDrawCBTable();
    }
    return g_UIUserDrawCBTable_instance;
}
