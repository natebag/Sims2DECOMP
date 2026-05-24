// 0x801F0050 INVTarget::OnSetCurrentTab(int) (164B)
//
// GCC canonicalizes stwx/lwzx operand order to (val, base, idx); DOL has
// (val, idx, base). swap_operands directives flip back to source order.

// ASMPROC_swap_operands: match="stwx 4,8,9" pos=1,2
// ASMPROC_swap_operands: match="lwzx 3,8,9" pos=1,2

struct INVTarget;

extern int StaticConvertTabToCategory(int category);
extern void InstallInventoryPanelShaders(INVTarget* self, int category);

extern int g_currentCellArray[1];    // SDA r13-28708, per-tab current cell index
extern int g_currentDirtyArray[1];   // SDA r13-28700, per-tab dirty flag

struct INVTarget {
    char pad000[0x84];
    int m_currentTab;        // 0x84
    char pad088[0x90 - 0x84 - 4];
    void* m_invHelper;       // 0x90
    char pad094[0xBC - 0x90 - 4];
    int m_tabCount;          // 0xBC
    int OnSetCurrentTab(int tab);
};

int INVTarget::OnSetCurrentTab(int tab) {
    if (m_invHelper == 0) return 0;

    if (tab < 0) {
        tab = m_tabCount - 1;
    } else if (tab >= m_tabCount) {
        tab = 0;
    }

    g_currentCellArray[m_currentTab] = tab;
    g_currentDirtyArray[m_currentTab] = 0;

    int category = StaticConvertTabToCategory(g_currentCellArray[m_currentTab]);
    InstallInventoryPanelShaders(this, category);

    return 1;
}
