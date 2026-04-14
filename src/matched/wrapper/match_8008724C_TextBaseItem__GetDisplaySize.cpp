// 0x8008724C (8 bytes)
struct EVec2 { float x; float y; };

class TextBaseItem {
public:
    char pad[44];
    EVec2 m_displaySize;

    EVec2 *GetDisplaySize(void);
};

EVec2 *TextBaseItem::GetDisplaySize(void) {
    return &m_displaySize;
}
