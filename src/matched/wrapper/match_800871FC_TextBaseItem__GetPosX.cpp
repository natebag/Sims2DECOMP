// 0x800871FC (8 bytes)
class TextBaseItem {
public:
    char pad[36];
    float m_posX;

    float GetPosX(void);
};

float TextBaseItem::GetPosX(void) {
    return m_posX;
}
