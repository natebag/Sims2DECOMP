struct TextBaseItem {
    char pad[0x2C];
    float m_displaySizeX;

    float GetDisplaySizeX(void);
};

float TextBaseItem::GetDisplaySizeX(void) {
    return m_displaySizeX;
}
