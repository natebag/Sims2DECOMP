// 0x80178bf8 (44B) GetVariableCommandTable::Instance(void)

struct GetVariableCommandTable {
    char data[16];
    GetVariableCommandTable();
    static GetVariableCommandTable* Instance();
};

extern GetVariableCommandTable* g_GetVariableCommandTable_instance;

GetVariableCommandTable* GetVariableCommandTable::Instance() {
    if (!g_GetVariableCommandTable_instance) {
        g_GetVariableCommandTable_instance = new GetVariableCommandTable();
    }
    return g_GetVariableCommandTable_instance;
}
