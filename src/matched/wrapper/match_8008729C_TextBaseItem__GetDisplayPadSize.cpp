// 0x8008729C (8 bytes)
struct EVec2 { float x; float y; };

class TextBaseItem {
public:
    char pad[52];
    EVec2 m_displayPadSize;

    EVec2 *GetDisplayPadSize(void);
};

EVec2 *TextBaseItem::GetDisplayPadSize(void) {
    return &m_displayPadSize;
}
