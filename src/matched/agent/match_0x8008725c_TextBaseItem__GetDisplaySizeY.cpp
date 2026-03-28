struct TextBaseItem {
    char pad[0x30];
    float m_displaySizeY;

    float GetDisplaySizeY(void);
};

float TextBaseItem::GetDisplaySizeY(void) {
    return m_displaySizeY;
}
