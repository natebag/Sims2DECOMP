/* 0x80088EA0 (64 bytes) - DialogPaneBase::SetBodyFont(ERFont *) */

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
    char _pad_0[0x64];
    WrapperPaneBase *m_bodyPane;

    void SetBodyFont(ERFont *font);
};

void DialogPaneBase::SetBodyFont(ERFont *font)
{
    WrapperPaneBase *pane = m_bodyPane;
    TextBlock *tb = (TextBlock *)((char *)pane + 0x20);
    tb->m_font = font;
    tb->SetDirty();
    pane->m_flags |= 0x02;
}
