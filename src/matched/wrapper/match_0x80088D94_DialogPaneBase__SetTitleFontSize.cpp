/* 0x80088D94 (64 bytes) - DialogPaneBase::SetTitleFontSize(float) */

class TextBlock {
public:
    char _pad_0[0x34];
    float m_fontSize;
    void SetDirty(void);
};

class WrapperPaneBase {
public:
    char _pad_0[4];
    unsigned int m_flags;
};

class DialogPaneBase {
public:
    char _pad_0[0x60];
    WrapperPaneBase *m_titlePane;

    void SetTitleFontSize(float size);
};

void DialogPaneBase::SetTitleFontSize(float size)
{
    WrapperPaneBase *pane = m_titlePane;
    TextBlock *tb = (TextBlock *)((char *)pane + 0x20);
    tb->m_fontSize = size;
    tb->SetDirty();
    pane->m_flags |= 0x02;
}
