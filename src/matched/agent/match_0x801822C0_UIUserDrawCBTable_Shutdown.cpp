// 0x801822C0 (72B) UIUserDrawCBTable::Shutdown(void)

struct UIUserDrawCBTable_Base { char pad[12]; };

struct UIUserDrawCBTable_Impl : public UIUserDrawCBTable_Base {
    virtual void Destroy(int mode) = 0;
};

extern UIUserDrawCBTable_Impl* g_UIUserDrawCBTable_instance;

struct UIUserDrawCBTable {
    static void Shutdown();
};

void UIUserDrawCBTable::Shutdown() {
    if (g_UIUserDrawCBTable_instance) {
        g_UIUserDrawCBTable_instance->Destroy(3);
        g_UIUserDrawCBTable_instance = 0;
    }
}
