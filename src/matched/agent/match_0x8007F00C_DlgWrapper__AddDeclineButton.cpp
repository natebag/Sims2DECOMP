void DW_AddButton(void *, int, int, void *);

struct DW_AddDeclineButton {
    char _pad[0xAC];
    void *m_pane;

    void AddDeclineButton(void *text);
};

void DW_AddDeclineButton::AddDeclineButton(void *text) {
    DW_AddButton(m_pane, 1, 1, text);
}
