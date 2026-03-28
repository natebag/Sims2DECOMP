class CASSelectionTarget {
public:
    char _pad[0x548];
    int m_page;

    void ScrollPageLeft(void);
    void ClearTextures(unsigned int start, unsigned int end);
    void ShiftShaderTexturesRight(void);
    void UpdateSelectionArrowState(void);
    void LoadGridTextures(unsigned int start, unsigned int end);
};

void CASSelectionTarget::ScrollPageLeft(void) {
    if (m_page == 1) {
        return;
    }
    ClearTextures(12, 15);
    ShiftShaderTexturesRight();
    m_page--;
    UpdateSelectionArrowState();
    LoadGridTextures(0, 3);
}
