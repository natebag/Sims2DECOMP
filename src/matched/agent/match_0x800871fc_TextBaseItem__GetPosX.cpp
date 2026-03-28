struct TextBaseItem {
    char pad[0x24];
    float m_posX;

    float GetPosX(void);
};

float TextBaseItem::GetPosX(void) {
    return m_posX;
}
