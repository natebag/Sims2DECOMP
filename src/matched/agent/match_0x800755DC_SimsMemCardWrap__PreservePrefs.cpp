// 0x800755DC SimsMemCardWrap::PreservePrefs (40b)

extern int g_prefsPtr[];

extern void PreservePrefsImpl(void*);

void SimsMemCardWrap_PreservePrefs(void) {
    void* ptr = *(void**)((char*)g_prefsPtr + 0);
    PreservePrefsImpl(ptr);
}
