struct TextBaseItem {
    char pad[0x38];
    float m_displayPadSizeY;

    float GetDisplayPadSizeY(void);
};

float TextBaseItem::GetDisplayPadSizeY(void) {
    return m_displayPadSizeY;
}
