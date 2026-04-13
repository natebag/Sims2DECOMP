// 0x800755DC SimsMemCardWrap::PreservePrefs (40B)

extern char g_prefsInstance[];
extern void OptionsRecon_PreservePreferences(void*);

struct SimsMemCardWrap {
    void PreservePrefs();
};

void SimsMemCardWrap::PreservePrefs() {
    OptionsRecon_PreservePreferences(*(void**)g_prefsInstance);
}
