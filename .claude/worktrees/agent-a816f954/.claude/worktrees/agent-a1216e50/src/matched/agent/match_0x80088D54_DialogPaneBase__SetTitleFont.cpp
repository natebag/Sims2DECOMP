/* 0x80088D54 (64 bytes) - DialogPaneBase::SetTitleFont(ERFont *) */

class TextBlock {
public:
    char _pad_0[0x30];
    void *m_font;
    void SetDirty(void);
};

class ERFont;

class WrapperPaneBase {
public:
    char _pad_0[4];
    unsigned int m_flags;
};

class DialogPaneBase {
public:
    char _pad_0[0x60];
    WrapperPaneBase *m_titlePane;

    void SetTitleFont(ERFont *font);
};

void DialogPaneBase::SetTitleFont(ERFont *font)
{
    WrapperPaneBase *pane = m_titlePane;
    TextBlock *tb = (TextBlock *)((char *)pane + 0x20);
    tb->m_font = font;
    tb->SetDirty();
    pane->m_flags |= 0x02;
}
