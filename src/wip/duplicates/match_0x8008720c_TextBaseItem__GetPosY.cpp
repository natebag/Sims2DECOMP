struct TextBaseItem {
    char pad[0x28];
    float m_posY;

    float GetPosY(void);
};

float TextBaseItem::GetPosY(void) {
    return m_posY;
}
