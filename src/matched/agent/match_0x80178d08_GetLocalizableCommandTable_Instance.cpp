// 0x80178d08 (60B) GetLocalizableCommandTable::Instance(void)

struct GetLocalizableCommandTable {
    char data[16];
    GetLocalizableCommandTable();
    static GetLocalizableCommandTable* Instance();
};

extern GetLocalizableCommandTable* g_GetLocalizableCommandTable_instance;

GetLocalizableCommandTable* GetLocalizableCommandTable::Instance() {
    if (!g_GetLocalizableCommandTable_instance) {
        g_GetLocalizableCommandTable_instance = new GetLocalizableCommandTable();
    }
    return g_GetLocalizableCommandTable_instance;
}
