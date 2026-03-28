// 0x800871F4 (8 bytes)
class TextBaseItem {
public:
    char pad[36];
    float m_posX;

    void SetPosX(float x);
};

void TextBaseItem::SetPosX(float x) {
    m_posX = x;
}
