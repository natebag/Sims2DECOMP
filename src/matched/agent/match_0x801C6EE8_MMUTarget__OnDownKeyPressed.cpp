/* MMUTarget::OnDownKeyPressed(char *, char *) at 0x801C6EE8 (156b) */

struct MMUTarget {
    char pad_00[0x8C];
    int m_menuMode;
    char pad_90[0x08];
    unsigned int m_lotIndex;
    unsigned int m_nghIndex;
    unsigned int m_maxLotItems;
    char pad_A4[0x0C];
    int m_screenMode;

    void OnDownKeyPressed(char *a, char *b);
    void IncrementChoice(char *a, char *b);
    void UpdateNGHListItems();
    void UpdateLotListItems();
};

void MMUTarget::OnDownKeyPressed(char *a, char *b) {
    if (m_screenMode == 4) {
        IncrementChoice(a, b);
        return;
    }
    if (m_menuMode == 1) {
        m_nghIndex = (m_nghIndex + 1) % 6;
        UpdateNGHListItems();
        return;
    }
    if (m_menuMode == 2) {
        m_lotIndex = (m_lotIndex + 1) % m_maxLotItems;
        UpdateLotListItems();
    }
}
