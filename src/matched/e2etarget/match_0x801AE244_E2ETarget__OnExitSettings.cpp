// 0x801AE244 E2ETarget::OnExitSettings(void) (128B)

class UIObjectBase {
public:
    static void AptViewer_CallFunction(char* funcName, char* a, char* b, int n, char** args);
};

class E2ETarget {
public:
    char _pad0[200];
    float m_savedHue;
    float m_savedSat;
    float m_savedVal;
    float m_savedExp;
    void OnExitSettings();
    void LaunchSaveSettingsDialog();
};

extern float gv_E2ETarget_curHue;
extern float gv_E2ETarget_curSat;
extern float gv_E2ETarget_curVal;
extern float gv_E2ETarget_curExp;

void E2ETarget::OnExitSettings() {
    if (m_savedHue != gv_E2ETarget_curHue
        || m_savedSat != gv_E2ETarget_curSat
        || m_savedVal != gv_E2ETarget_curVal
        || m_savedExp != gv_E2ETarget_curExp) {
        LaunchSaveSettingsDialog();
    } else {
        UIObjectBase::AptViewer_CallFunction((char*)"E2E_OnExit", (char*)0, (char*)0, 0, (char**)0);
    }
}
