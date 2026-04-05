void DW_AddButton(void *, int, int, void *);

struct DW_AAB {
    char _pad[0xAC];
    void *m_pane;

    void AddAcceptButton(void *text);
};

void DW_AAB::AddAcceptButton(void *text) {
    DW_AddButton(m_pane, 0, 1, text);
}
