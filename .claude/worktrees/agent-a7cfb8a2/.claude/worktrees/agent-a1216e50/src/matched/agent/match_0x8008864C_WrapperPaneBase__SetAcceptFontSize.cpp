/* 0x8008864C (84 bytes) - WrapperPaneBase::SetAcceptFontSize(float) */

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
};

class WrapperPaneBase {
public:
    char _pad_0[0x40];
    TextBaseItem *m_acceptButton;

    void UpdateAptButtonWidth(int type);
    void SetAcceptFontSize(float size);
};

void WrapperPaneBase::SetAcceptFontSize(float size)
{
    TextBaseItem *btn = m_acceptButton;
    TextBlock *tb = &btn->m_textBlock;
    tb->m_fontSize = size;
    tb->SetDirty();
    btn->m_flags |= 0x02;
    UpdateAptButtonWidth(0);
}
