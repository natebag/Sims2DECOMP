/* 0x800889C4 (80 bytes) - WrapperPaneBase::SetAlt1Font(ERFont *) */

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
};

class WrapperPaneBase {
public:
    char _pad_0[0x48];
    TextBaseItem *m_alt1Button;

    void UpdateAptButtonWidth(int type);
    void SetAlt1Font(ERFont *font);
};

void WrapperPaneBase::SetAlt1Font(ERFont *font)
{
    TextBaseItem *btn = m_alt1Button;
    TextBlock *tb = &btn->m_textBlock;
    tb->m_font = font;
    tb->SetDirty();
    btn->m_flags |= 0x02;
    UpdateAptButtonWidth(2);
}
