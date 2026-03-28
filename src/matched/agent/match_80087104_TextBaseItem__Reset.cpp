// 0x80087104 (12 bytes)
class TextBaseItem {
public:
    int pad;
    int m_needsUpdate;

    void Reset(void);
};

void TextBaseItem::Reset(void) {
    m_needsUpdate = 1;
}
