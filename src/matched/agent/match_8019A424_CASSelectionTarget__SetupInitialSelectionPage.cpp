class CASSelectionTarget {
public:
    char _pad_8C[0x8C];
    int m_optionCount;
    char _pad_548[0x548 - 0x90];
    int m_page;

    void SetupInitialSelectionPage(void);
    void ClearTextures(void);
    void LoadGridTextures(unsigned int start, unsigned int end);
    void UpdateSelectionArrowState(void);
};

void CASSelectionTarget::SetupInitialSelectionPage(void) {
    m_page = 1;
    ClearTextures();
    int end = m_optionCount;
    if (end > 0) {
        end = end + 4;
        if (end > 15) {
            end = 15;
        }
        LoadGridTextures(4, end);
    }
    UpdateSelectionArrowState();
}
