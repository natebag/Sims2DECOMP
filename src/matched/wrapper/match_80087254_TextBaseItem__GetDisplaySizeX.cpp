// 0x80087254 (8 bytes)
class TextBaseItem {
public:
    char pad[44];
    float m_displaySizeX;

    float GetDisplaySizeX(void);
};

float TextBaseItem::GetDisplaySizeX(void) {
    return m_displaySizeX;
}
