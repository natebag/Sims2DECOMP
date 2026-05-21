// 0x801F7150 INVTarget::GetOnMsgInvShpShpTabToInvTab(char *) (104B)
// ASMPROC_swap_operands: match="lwzx 3,3,9" pos=1,2

extern int ConvertShoppingCategoryToInventoryCategory(int);
extern "C" int Sprintf(char* dst, char* fmt, ...);
extern char g_tab_fmt[];

class INVTarget {
public:
    char _pad0[376];
    int* m_tabs_begin;

    int GetSelectedShoppingCategoryListIdx();
    void InstallInventoryPanelShaders(int);
    void GetOnMsgInvShpShpTabToInvTab(char* out);
};

void INVTarget::GetOnMsgInvShpShpTabToInvTab(char* out) {
    int idx = GetSelectedShoppingCategoryListIdx();
    int tab_entry = *(int*)((unsigned int)m_tabs_begin + idx * 8);
    int n = ConvertShoppingCategoryToInventoryCategory(tab_entry);
    InstallInventoryPanelShaders(n);
    Sprintf(out, g_tab_fmt, n - 1);
}
