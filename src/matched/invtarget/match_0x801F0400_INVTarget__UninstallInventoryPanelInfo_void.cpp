// 0x801F0400 INVTarget::UninstallInventoryPanelInfo(void) (184B)

struct UI2D;

extern int ContainsEntry(UI2D* target, char* id);
extern void UnInstallEntry(UI2D* target, char* id);
extern void UIDBSetString(char* key, unsigned short* value);

extern char* g_invPanelIdTable[][12];     // 0x803FBF5C
extern char* g_invPanelNameTable[][12];   // 0x803FC25C
extern unsigned short g_emptyWString[];   // 0x803F8964

struct INVTarget {
    UI2D* m_field00;        // 0x00
    char pad04[0x18];
    UI2D* m_field1C;        // 0x1C
    char pad20[0x64];
    int m_currentTab;       // 0x84
    void UninstallInventoryPanelInfo(void);
};

void INVTarget::UninstallInventoryPanelInfo(void) {
    for (unsigned int i = 0; i < 12U; ++i) {
        char* id = g_invPanelIdTable[m_currentTab][i];
        if (ContainsEntry(m_field1C, id)) {
            if (m_field00 && m_field1C) {
                UnInstallEntry(m_field1C, id);
            }
        }
        UIDBSetString(g_invPanelNameTable[m_currentTab][i], g_emptyWString);
    }
}
