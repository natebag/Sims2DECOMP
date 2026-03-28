/* MMUTarget::OnUpKeyPressed(char *, char *) at 0x801C6E5C (140b) */

struct MMUTarget {
    char pad_00[0x8C];
    int m_menuMode;
    char pad_90[0x08];
    int m_lotIndex;
    int m_nghIndex;
    int m_maxLotItems;
    char pad_A4[0x0C];
    int m_screenMode;

    void OnUpKeyPressed(char *a, char *b);
    void DecrementChoice(char *a, char *b);
    void UpdateNGHListItems();
    void UpdateLotListItems();
};

void MMUTarget::OnUpKeyPressed(char *a, char *b) {
    if (m_screenMode == 4) {
        DecrementChoice(a, b);
        return;
    }
    if (m_menuMode == 1) {
        m_nghIndex--;
        if (m_nghIndex < 0) {
            m_nghIndex = 5;
        }
        UpdateNGHListItems();
        return;
    }
    if (m_menuMode == 2) {
        m_lotIndex--;
        if (m_lotIndex < 0) {
            m_lotIndex = m_maxLotItems - 1;
        }
        UpdateLotListItems();
    }
}
