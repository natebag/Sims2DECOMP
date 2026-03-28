/* 0x8008735C (64 bytes) - TextBaseItem::SetFontSize(float) */

class TextBlock {
public:
    char _pad_0[0x34];
    float m_fontSize;
    void SetDirty(void);
};

class TextBaseItem {
public:
    char _pad_0[4];
    unsigned int m_flags;
    char _pad_8[0x18];
    TextBlock m_textBlock;

    void SetFontSize(float size);
};

void TextBaseItem::SetFontSize(float size)
{
    TextBlock *tb = &m_textBlock;
    tb->m_fontSize = size;
    tb->SetDirty();
    m_flags |= 0x02;
}
