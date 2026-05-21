// 0x801DCE2C R2LTarget::onSummaryDialogSelection(int) (76B)

class HelpDialogCallback {};

class HelpDialog {
public:
    void SpawnHelpDialog(int a, char* b, HelpDialogCallback* cb, bool c, char* d);
};

extern char s_r2lSummary[];   // 0x803F50BC

class R2LTarget {
public:
    char pad_000[132];
    HelpDialogCallback m_cb;
    char pad_84[12];
    int  m_arg148;
    char pad_98[32];
    int  m_dialogHandle;
    char pad_BC[136];
    HelpDialog m_helpDialog;
    void onSummaryDialogSelection(int sel);
};

void R2LTarget::onSummaryDialogSelection(int sel) {
    m_dialogHandle = 0;
    if (sel != 0) return;
    m_helpDialog.SpawnHelpDialog(m_arg148, s_r2lSummary, &m_cb, false, 0);
}
