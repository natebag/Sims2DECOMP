/* O2TTarget::OnSaveSettingsDialogClose(int) at 0x801CEEE8 (120B) */

typedef char* CharPtr;

struct UIObjectBase {
    static void AptViewer_CallFunction(char*, CharPtr, CharPtr, int, CharPtr*);
};

extern char s_o2tDialogStr[];

struct O2TTarget {
    char pad_000[0x88];
    int m_field88;
    char pad_08C[0x258 - 0x8C];
    int m_field258;

    void OnSaveSettingsDialogClose(int result);
    void RestoreAudioOptions();
    void RestoreGameOptions();
};

void O2TTarget::OnSaveSettingsDialogClose(int result) {
    if (result == 1) {
        if (m_field88 == 1) {
            RestoreAudioOptions();
        } else if (m_field88 == 2) {
            RestoreGameOptions();
        }
    }
    UIObjectBase::AptViewer_CallFunction(s_o2tDialogStr, (CharPtr)0, (CharPtr)0, 0, (CharPtr*)0);
    m_field258 = 0;
}
