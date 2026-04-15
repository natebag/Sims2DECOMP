// 0x80178D44 (72B) GetLocalizableCommandTable::Shutdown(void)

struct GetLocalizableCommandTable_Base { char pad[12]; };

struct GetLocalizableCommandTable_Impl : public GetLocalizableCommandTable_Base {
    virtual void Destroy(int mode) = 0;
};

extern GetLocalizableCommandTable_Impl* g_GetLocalizableCommandTable_instance;

struct GetLocalizableCommandTable {
    static void Shutdown();
};

void GetLocalizableCommandTable::Shutdown() {
    if (g_GetLocalizableCommandTable_instance) {
        g_GetLocalizableCommandTable_instance->Destroy(3);
        g_GetLocalizableCommandTable_instance = 0;
    }
}
