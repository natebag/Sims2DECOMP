// 0x801F5E58 INVTarget::SetOnMsgInvShpNextTab(char *) (104B)

class INVTarget {
public:
    char _pad0[376];
    char* m_tabs_begin;
    char* m_tabs_end;
    char _pad384[12880 - 384];
    unsigned char m_curTab;
    unsigned char m_field12881;

    void InstallShoppingPanelShaders();
    void SetOnMsgInvShpNextTab(char* a);
};

struct TabsVec { char* begin; char* end; };

void INVTarget::SetOnMsgInvShpNextTab(char* a) {
    TabsVec* tabs = (TabsVec*)&m_tabs_begin;
    char* begin = m_tabs_begin;
    unsigned int diff = (unsigned int)(tabs->end - begin);
    if (diff >> 3 == 0) return;
    int curTab = m_curTab;
    m_field12881 = 0;
    curTab = curTab + 1;
    int count = (tabs->end - begin) >> 3;
    m_curTab = (unsigned char)((unsigned int)curTab % (unsigned int)count);
    InstallShoppingPanelShaders();
}
