// 0x80181D88 (76B) UIUpdateTable::Shutdown(void)

struct UIUpdateTable_Base { char pad[12]; };

struct UIUpdateTable_Impl : public UIUpdateTable_Base {
    virtual void Destroy(int mode) = 0;
};

extern UIUpdateTable_Impl* g_UIUpdateTable_instance;

struct UIUpdateTable {
    static void Shutdown();
};

void UIUpdateTable::Shutdown() {
    if (g_UIUpdateTable_instance) {
        g_UIUpdateTable_instance->Destroy(3);
        g_UIUpdateTable_instance = 0;
    }
}
