/* 0x80088EE0 (64 bytes) - DialogPaneBase::SetBodyFontSize(float) */

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
    char _pad_0[0x64];
    WrapperPaneBase *m_bodyPane;

    void SetBodyFontSize(float size);
};

void DialogPaneBase::SetBodyFontSize(float size)
{
    WrapperPaneBase *pane = m_bodyPane;
    TextBlock *tb = (TextBlock *)((char *)pane + 0x20);
    tb->m_fontSize = size;
    tb->SetDirty();
    pane->m_flags |= 0x02;
}
