// 0x80075604 (40B) SimsMemCardWrap::RestorePrefs(void)

struct Prefs;
extern char g_prefsPtr[16];
extern int DoRestore(Prefs*);

struct SimsMemCardWrap {
    void RestorePrefs();
};

void SimsMemCardWrap::RestorePrefs() {
    DoRestore(*(Prefs**)g_prefsPtr);
}
