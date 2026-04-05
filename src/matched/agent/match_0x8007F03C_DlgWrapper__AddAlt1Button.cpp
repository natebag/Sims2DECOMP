void DW_AddButton(void *, int, int, void *);

struct DW_AddAlt1Button {
    char _pad[0xAC];
    void *m_pane;

    void AddAlt1Button(void *text);
};

void DW_AddAlt1Button::AddAlt1Button(void *text) {
    DW_AddButton(m_pane, 2, 1, text);
}
