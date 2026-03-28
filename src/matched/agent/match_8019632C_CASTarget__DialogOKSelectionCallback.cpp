class UIDialog {
public:
    void HideDialog(void);
};

class CASTarget {
public:
    char _pad[0x8C];
    int m_handleInput;
    char _pad2[0x130C];
    UIDialog m_okDialog;

    void SetHandleInput(bool value);
    void DialogOKSelectionCallback(int result);
};

void CASTarget::DialogOKSelectionCallback(int result) {
    SetHandleInput(1);
    m_okDialog.HideDialog();
}
