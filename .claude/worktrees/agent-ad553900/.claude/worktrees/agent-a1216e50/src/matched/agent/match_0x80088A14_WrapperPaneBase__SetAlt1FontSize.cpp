/* 0x80088A14 (84 bytes) - WrapperPaneBase::SetAlt1FontSize(float) */

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
    char _pad_0[0x48];
    TextBaseItem *m_alt1Button;

    void UpdateAptButtonWidth(int type);
    void SetAlt1FontSize(float size);
};

void WrapperPaneBase::SetAlt1FontSize(float size)
{
    TextBaseItem *btn = m_alt1Button;
    TextBlock *tb = &btn->m_textBlock;
    tb->m_fontSize = size;
    tb->SetDirty();
    btn->m_flags |= 0x02;
    UpdateAptButtonWidth(2);
}
