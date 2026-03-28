class CASSelectionTarget {
public:
    char _pad[0x544];
    int m_maxPage;
    int m_page;

    void ScrollPageRight(void);
    void ClearTextures(unsigned int start, unsigned int end);
    void ShiftShaderTexturesLeft(void);
    void UpdateSelectionArrowState(void);
    void LoadGridTextures(unsigned int start, unsigned int end);
};

void CASSelectionTarget::ScrollPageRight(void) {
    if (m_page == m_maxPage) {
        return;
    }
    ClearTextures(0, 3);
    ShiftShaderTexturesLeft();
    m_page++;
    UpdateSelectionArrowState();
    LoadGridTextures(12, 15);
}
