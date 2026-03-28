/* 0x80087314 (64 bytes) - TextBaseItem::SetFont(ERFont *) */

class TextBlock {
public:
    char _pad_0[0x30];
    void *m_font;
    void SetDirty(void);
};

class ERFont;

class TextBaseItem {
public:
    char _pad_0[4];
    unsigned int m_flags;
    char _pad_8[0x18];
    TextBlock m_textBlock;

    void SetFont(ERFont *font);
};

void TextBaseItem::SetFont(ERFont *font)
{
    TextBlock *tb = &m_textBlock;
    tb->m_font = font;
    tb->SetDirty();
    m_flags |= 0x02;
}
