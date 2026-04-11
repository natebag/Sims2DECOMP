// 0x800AAA40 castSkillToString (68b)

extern void* g_skillTable;
extern char g_noneString[];

void* GetSkillName(void* table, int index);

const char* castSkillToString(int skill) {
    if (skill == 0) {
        return g_noneString;
    }
    void* name = GetSkillName(g_skillTable, skill);
    if (name) {
        return (const char*)name;
    }
    return g_noneString;
}
