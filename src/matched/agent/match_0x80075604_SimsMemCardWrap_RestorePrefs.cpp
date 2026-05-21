// 0x80075604 SimsMemCardWrap::RestorePrefs (40b)

struct OptionsReconGlobal {
    int* ptr;
    int pad[2];
};
extern OptionsReconGlobal g_pOptionsRecon;
extern int OptionsRecon__RestorePreferences_void(int*);

void SimsMemCardWrap_RestorePrefs() {
    OptionsRecon__RestorePreferences_void(g_pOptionsRecon.ptr);
}
