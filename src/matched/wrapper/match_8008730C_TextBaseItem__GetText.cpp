// 0x8008730C (8 bytes)
class TextBaseItem {
public:
    char pad[32];
    void *m_text;

    void *GetText(void) const;
};

void *TextBaseItem::GetText(void) const {
    return m_text;
}
