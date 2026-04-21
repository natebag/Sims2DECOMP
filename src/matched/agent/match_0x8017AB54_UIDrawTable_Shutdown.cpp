// 0x8017AB54 (76B) UIDrawTable::Shutdown(void)

struct UIDrawTable_Base { char pad[12]; };

struct UIDrawTable_Impl : public UIDrawTable_Base {
    virtual void Destroy(int mode) = 0;
};

extern UIDrawTable_Impl* g_UIDrawTable_instance;

struct UIDrawTable {
    static void Shutdown();
};

void UIDrawTable::Shutdown() {
    if (g_UIDrawTable_instance) {
        g_UIDrawTable_instance->Destroy(3);
        g_UIDrawTable_instance = 0;
    }
}
