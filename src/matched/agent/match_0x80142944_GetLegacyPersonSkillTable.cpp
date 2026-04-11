/* GetLegacyPersonSkillTable(void) at 0x80142944 (12B) */
/* lwz r9, -0x7B9C(r13); lwz r3, 0x18(r9); blr */
// NOTE: SDA function - uses r13-relative addressing. Verified standalone won't match
// due to link-time address resolution. Code is functionally correct.

struct SkillTableManager {
    char _pad[0x18];
    void* personSkillTable;
};

extern SkillTableManager* g_skillTableManager;

void* GetLegacyPersonSkillTable(void) {
    return g_skillTableManager->personSkillTable;
}
