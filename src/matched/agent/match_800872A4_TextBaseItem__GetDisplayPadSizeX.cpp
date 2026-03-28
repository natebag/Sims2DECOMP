// 0x800872A4 (8 bytes)
class TextBaseItem {
public:
    char pad[52];
    float m_displayPadSizeX;

    float GetDisplayPadSizeX(void);
};

float TextBaseItem::GetDisplayPadSizeX(void) {
    return m_displayPadSizeX;
}
