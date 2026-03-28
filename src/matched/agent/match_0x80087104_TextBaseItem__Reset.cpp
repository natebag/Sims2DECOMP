struct TextBaseItem {
    char pad[0x04];
    int m_needsUpdate;

    void Reset(void);
};

void TextBaseItem::Reset(void) {
    m_needsUpdate = 1;
}
