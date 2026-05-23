// 0x801F0904 INVTarget::Cheat_HandleReturnUpHierarchy(char*) (132B)

struct INVTarget;

extern void ClearAllCheatStrings(INVTarget* self);

extern char s_lockedStr[];     // 0x803F8798
extern char s_unlockedStr[];   // 0x803F879C

struct INVTarget {
    char pad000[0x138];
    unsigned char m_cheatHierarchyLevel;   // 0x138
    char pad139[0x189 - 0x138 - 1];
    unsigned char m_field189;              // 0x189
    unsigned char m_field18A;              // 0x18A
    char pad18B[0x3251 - 0x18A - 1];
    unsigned char m_field3251;             // 0x3251
    void Cheat_HandleReturnUpHierarchy(char* out);
};

void INVTarget::Cheat_HandleReturnUpHierarchy(char* out) {
    int level = m_cheatHierarchyLevel;
    if (level != 1) {
        if (level > 1) return;
        if (level != 0) return;
        *(short*)out = *(short*)s_lockedStr;
        m_field189 = 0;
        return;
    }
    *(short*)out = *(short*)s_unlockedStr;
    m_field18A = 1;
    --m_cheatHierarchyLevel;
    ClearAllCheatStrings(this);
    *(volatile unsigned char*)&m_field3251 = 0;
    *(volatile unsigned char*)&m_field189 = 0;
}
