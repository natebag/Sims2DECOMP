struct TextBaseItem {
    char pad[0x24];
    float m_posX;

    void SetPosX(float x);
};

void TextBaseItem::SetPosX(float x) {
    m_posX = x;
}
