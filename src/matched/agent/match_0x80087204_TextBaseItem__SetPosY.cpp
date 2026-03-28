struct TextBaseItem {
    char pad[0x28];
    float m_posY;

    void SetPosY(float y);
};

void TextBaseItem::SetPosY(float y) {
    m_posY = y;
}
