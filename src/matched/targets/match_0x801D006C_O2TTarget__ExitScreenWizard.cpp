// 0x801D006C O2TTarget::ExitScreenWizard(char*, char*) (84B)
// TRIAGE

class UI2D {
public:
    void InstallEntry(char* a, unsigned int b, char* c, int d);
};

extern char s_o2tExitWizardLabel[];  // at 0x803F3988

class O2TTarget {
public:
    void* m_field0;
    char  pad_04[24];
    UI2D* m_field28;
    char  pad_20[92];
    char* m_field124;
    void ExitScreenWizard(char*, char*);
};

void O2TTarget::ExitScreenWizard(char*, char*) {
    void* f0 = m_field0;
    char* lbl = s_o2tExitWizardLabel;
    if (f0 == 0) return;
    UI2D* ui = m_field28;
    if (ui == 0) return;
    ui->InstallEntry(lbl, 0x9F93FF74u, m_field124, 0);
}
