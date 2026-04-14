/* 0x80088388 (76 bytes) - WrapperPaneBase::SetButtonText(WrapperPaneBase::ButtonType, unsigned wchar_t *) */

typedef int ButtonType;
typedef unsigned short wchar_t_ea;

class TextBaseItem {
public:
    void SetText(wchar_t_ea *text);
};

class WrapperPaneBase {
public:
    char _pad_0[0x40];
    TextBaseItem *m_buttons[3];

    void UpdateAptButtonWidth(ButtonType type);
    void SetButtonText(ButtonType type, wchar_t_ea *text);
};

void WrapperPaneBase::SetButtonText(ButtonType type, wchar_t_ea *text)
{
    m_buttons[type]->SetText(text);
    UpdateAptButtonWidth(type);
}
