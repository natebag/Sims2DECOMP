// 0x80178c80 (60B) SetVariableCommandTable::Instance(void)

struct SetVariableCommandTable {
    char data[16];
    SetVariableCommandTable();
    static SetVariableCommandTable* Instance();
};

extern SetVariableCommandTable* g_SetVariableCommandTable_instance;

SetVariableCommandTable* SetVariableCommandTable::Instance() {
    if (!g_SetVariableCommandTable_instance) {
        g_SetVariableCommandTable_instance = new SetVariableCommandTable();
    }
    return g_SetVariableCommandTable_instance;
}
