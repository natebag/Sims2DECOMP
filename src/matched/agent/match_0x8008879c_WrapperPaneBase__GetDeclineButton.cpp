struct ButtonItem;

struct WrapperPaneBase {
    char pad[0x44];
    ButtonItem *m_declineButton;

    ButtonItem *GetDeclineButton(void);
};

ButtonItem *WrapperPaneBase::GetDeclineButton(void) {
    return m_declineButton;
}
