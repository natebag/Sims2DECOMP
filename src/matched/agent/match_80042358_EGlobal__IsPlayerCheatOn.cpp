// 0x80042358 (48 bytes) EGlobal::IsPlayerCheatOn(int) const
// ASMPROC_inject_before: before="lhz 0,156(3)" lines="li 3,1; blr; .L8:"
// ASMPROC_replace_insn: match="bc 4,2,.L7" replacement="bc 12,2,.L8"
struct EGlobal {
    char pad1[156];
    unsigned short m_cheats;
    char pad2[866];
    int m_configured;
    int IsPlayerCheatOn(int cheatBit) const;
};

int EGlobal::IsPlayerCheatOn(int cheatBit) const {
    if (!m_configured) {
        unsigned short v = m_cheats;
        int r = 0;
        if ((v >> cheatBit) & 1) {
            r = 1;
        }
        return r;
    }
    return 1;
}
