// 0x801ae1e4 E2ETarget::ShowHelp (60B)

struct HelpDialog {
    void SpawnHelpDialog(int, const char*, void*, bool, const char*);
};

class E2ETarget {
public:
    char _pad[500];
    HelpDialog m_helpDialog;

    void ShowHelp(void);
};

void E2ETarget::ShowHelp(void) {
    m_helpDialog.SpawnHelpDialog(0, "eye_help", 0, 1, 0);
}
