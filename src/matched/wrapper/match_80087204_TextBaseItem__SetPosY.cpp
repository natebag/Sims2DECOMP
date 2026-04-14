// 0x80087204 (8 bytes)
class TextBaseItem {
public:
    char pad[40];
    float m_posY;

    void SetPosY(float y);
};

void TextBaseItem::SetPosY(float y) {
    m_posY = y;
}
