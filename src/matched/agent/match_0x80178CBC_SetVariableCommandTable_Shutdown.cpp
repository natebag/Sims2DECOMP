// 0x80178CBC (76B) SetVariableCommandTable::Shutdown(void)

struct SetVariableCommandTable_Base { char pad[12]; };

struct SetVariableCommandTable_Impl : public SetVariableCommandTable_Base {
    virtual void Destroy(int mode) = 0;
};

extern SetVariableCommandTable_Impl* g_SetVariableCommandTable_instance;

struct SetVariableCommandTable {
    static void Shutdown();
};

void SetVariableCommandTable::Shutdown() {
    if (g_SetVariableCommandTable_instance) {
        g_SetVariableCommandTable_instance->Destroy(3);
        g_SetVariableCommandTable_instance = 0;
    }
}
