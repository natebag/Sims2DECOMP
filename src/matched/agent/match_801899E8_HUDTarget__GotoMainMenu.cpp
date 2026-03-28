void UIRouter_FlowGoto(char* target);

extern char g_mainMenuFlowTarget[];

class HUDTarget {
public:
    char _pad[0x100];
    unsigned char m_hudTransitionTarget;

    void GotoMainMenu(void);
};

void HUDTarget::GotoMainMenu(void) {
    m_hudTransitionTarget = 1;
    UIRouter_FlowGoto(g_mainMenuFlowTarget);
}
