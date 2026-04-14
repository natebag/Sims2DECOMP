// 0x80087198 (8 bytes)
class TextBaseItem {
public:
    char pad[68];
    void *m_color;

    void *GetColor(void);
};

void *TextBaseItem::GetColor(void) {
    return m_color;
}
