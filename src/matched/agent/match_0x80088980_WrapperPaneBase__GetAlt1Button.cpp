struct ButtonItem;

struct WrapperPaneBase {
    char pad[0x48];
    ButtonItem *m_alt1Button;

    ButtonItem *GetAlt1Button(void);
};

ButtonItem *WrapperPaneBase::GetAlt1Button(void) {
    return m_alt1Button;
}
