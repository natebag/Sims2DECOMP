// 0x8008720C (8 bytes)
class TextBaseItem {
public:
    char pad[40];
    float m_posY;

    float GetPosY(void);
};

float TextBaseItem::GetPosY(void) {
    return m_posY;
}
