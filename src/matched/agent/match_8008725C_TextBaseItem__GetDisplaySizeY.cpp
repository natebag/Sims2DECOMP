// 0x8008725C (8 bytes)
class TextBaseItem {
public:
    char pad[48];
    float m_displaySizeY;

    float GetDisplaySizeY(void);
};

float TextBaseItem::GetDisplaySizeY(void) {
    return m_displaySizeY;
}
