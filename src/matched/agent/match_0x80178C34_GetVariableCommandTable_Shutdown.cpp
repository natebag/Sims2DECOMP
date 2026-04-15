// 0x80178C34 (72B) GetVariableCommandTable::Shutdown(void)

struct GetVariableCommandTable_Base { char pad[12]; };

struct GetVariableCommandTable_Impl : public GetVariableCommandTable_Base {
    virtual void Destroy(int mode) = 0;
};

extern GetVariableCommandTable_Impl* g_GetVariableCommandTable_instance;

struct GetVariableCommandTable {
    static void Shutdown();
};

void GetVariableCommandTable::Shutdown() {
    if (g_GetVariableCommandTable_instance) {
        g_GetVariableCommandTable_instance->Destroy(3);
        g_GetVariableCommandTable_instance = 0;
    }
}
