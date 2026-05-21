// 0x801F5EC0 INVTarget::SetOnMsgInvShpPrevTab(char *) (108B)

struct TabsVec { char* begin; char* end; };

class INVTarget {
public:
    char _pad0[376];
    char* m_tabs_begin;
    char* m_tabs_end;
    char _pad384[12880 - 384];
    unsigned char m_curTab;
    unsigned char m_field12881;

    void InstallShoppingPanelShaders();
    void SetOnMsgInvShpPrevTab(char* a);
};

void INVTarget::SetOnMsgInvShpPrevTab(char* a) {
    TabsVec* tabs = (TabsVec*)&m_tabs_begin;
    char* begin = m_tabs_begin;
    unsigned int diff = (unsigned int)(tabs->end - begin);
    if (diff >> 3 == 0) return;
    int curTab = m_curTab;
    m_field12881 = 0;
    if (curTab == 0) {
        int count = (tabs->end - begin) >> 3;
        m_curTab = (unsigned char)(count - 1);
    } else {
        m_curTab = (unsigned char)(curTab - 1);
    }
    InstallShoppingPanelShaders();
}
