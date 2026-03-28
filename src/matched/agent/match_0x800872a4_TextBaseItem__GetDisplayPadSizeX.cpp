struct TextBaseItem {
    char pad[0x34];
    float m_displayPadSizeX;

    float GetDisplayPadSizeX(void);
};

float TextBaseItem::GetDisplayPadSizeX(void) {
    return m_displayPadSizeX;
}
