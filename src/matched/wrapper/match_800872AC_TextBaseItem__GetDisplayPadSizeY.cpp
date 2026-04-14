// 0x800872AC (8 bytes)
class TextBaseItem {
public:
    char pad[56];
    float m_displayPadSizeY;

    float GetDisplayPadSizeY(void);
};

float TextBaseItem::GetDisplayPadSizeY(void) {
    return m_displayPadSizeY;
}
