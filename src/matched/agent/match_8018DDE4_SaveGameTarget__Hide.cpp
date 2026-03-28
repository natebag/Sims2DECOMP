class UIDialog {
public:
    void HideDialog(void);
};

class SaveGameTarget {
public:
    char _pad[0x84];
    UIDialog m_dialog;

    void Hide(void);
};

void SaveGameTarget::Hide(void) {
    m_dialog.HideDialog();
}
