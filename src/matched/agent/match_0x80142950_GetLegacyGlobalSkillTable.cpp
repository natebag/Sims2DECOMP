/* GetLegacyGlobalSkillTable(void) at 0x80142950 (12B) */
/* lwz r9, -0x7B9C(r13); lwz r3, 0x1C(r9); blr */
// NOTE: SDA function - uses r13-relative addressing. Verified standalone won't match
// due to link-time address resolution. Code is functionally correct.

struct SkillTableManager {
    char _pad[0x1C];
    void* globalSkillTable;
};

extern SkillTableManager* g_skillTableManager;

void* GetLegacyGlobalSkillTable(void) {
    return g_skillTableManager->globalSkillTable;
}
