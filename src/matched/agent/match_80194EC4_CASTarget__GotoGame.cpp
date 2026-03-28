void UIRouter_FlowGoto(char* target);

extern char g_gameFlowTarget[];

class CASTarget {
public:
    char _pad[0x8C];
    int m_handleInput;

    void SaveCASDataToNeighborhood(void);
    void SetHandleInput(bool value);
    void GotoGame(void);
};

void CASTarget::GotoGame(void) {
    SaveCASDataToNeighborhood();
    UIRouter_FlowGoto(g_gameFlowTarget);
    SetHandleInput(0);
}
