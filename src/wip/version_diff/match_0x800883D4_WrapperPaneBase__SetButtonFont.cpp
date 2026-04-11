/* 0x800883D4 (96 bytes) - WrapperPaneBase::SetButtonFont(WrapperPaneBase::ButtonType, ERFont *) */

typedef int ButtonType;

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
    TextBaseItem *m_buttons[3];

    void UpdateAptButtonWidth(ButtonType type);
    void SetButtonFont(ButtonType type, ERFont *font);
};

void WrapperPaneBase::SetButtonFont(ButtonType type, ERFont *font)
{
    TextBaseItem *btn = m_buttons[type];
    TextBlock *tb = &btn->m_textBlock;
    tb->m_font = font;
    tb->SetDirty();
    btn->m_flags |= 0x02;
    UpdateAptButtonWidth(type);
}
