// 0x80175F68 HelpDialog::SelectionCallback(int) (72B)
// TRIAGE

class Listener {
public:
    virtual void M1(int sel);
};

class HelpDialog {
public:
    char pad_00[136];
    int  m_flag;
    Listener* m_listener;
    void SelectionCallback(int sel);
};

void HelpDialog::SelectionCallback(int sel) {
    Listener* l = m_listener;
    m_flag = 0;
    if (l == 0) return;
    l->M1(sel);
}
