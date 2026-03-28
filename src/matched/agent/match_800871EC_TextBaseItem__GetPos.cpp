// 0x800871EC (8 bytes)
struct EVec2 { float x; float y; };

class TextBaseItem {
public:
    char pad[36];
    EVec2 m_pos;

    EVec2 *GetPos(void);
};

EVec2 *TextBaseItem::GetPos(void) {
    return &m_pos;
}
