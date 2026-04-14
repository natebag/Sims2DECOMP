/* 0x800885FC (80 bytes) - WrapperPaneBase::SetAcceptFont(ERFont *) */

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
    char _pad_0[0x40];
    TextBaseItem *m_acceptButton;

    void UpdateAptButtonWidth(int type);
    void SetAcceptFont(ERFont *font);
};

void WrapperPaneBase::SetAcceptFont(ERFont *font)
{
    TextBaseItem *btn = m_acceptButton;
    TextBlock *tb = &btn->m_textBlock;
    tb->m_font = font;
    tb->SetDirty();
    btn->m_flags |= 0x02;
    UpdateAptButtonWidth(0);
}
