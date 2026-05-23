struct ButtonItem;

struct WrapperPaneBase {
    char pad[0x40];
    ButtonItem *m_acceptButton;

    ButtonItem *GetAcceptButton(void);
};

ButtonItem *WrapperPaneBase::GetAcceptButton(void) {
    return m_acceptButton;
}
