/* GetMiscSkillTable(void) at 0x8014295C (12B) */
/* lwz r9, -0x7B9C(r13); lwz r3, 0x20(r9); blr */
// NOTE: SDA function - uses r13-relative addressing. Verified standalone won't match
// due to link-time address resolution. Code is functionally correct.

struct SkillTableManager {
    char _pad[0x20];
    void* miscSkillTable;
};

extern SkillTableManager* g_skillTableManager;

void* GetMiscSkillTable(void) {
    return g_skillTableManager->miscSkillTable;
}
