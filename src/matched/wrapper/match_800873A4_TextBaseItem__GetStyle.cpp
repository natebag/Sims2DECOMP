// 0x800873A4 (8 bytes)
class TextBaseItem {
public:
    char pad[108];
    int m_style;

    int GetStyle(void) const;
};

int TextBaseItem::GetStyle(void) const {
    return m_style;
}
