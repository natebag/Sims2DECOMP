// FLAGS: -fno-elide-constructors
struct EGlobal {
    char pad1[156]; unsigned short m_cheats;
    char pad2[866]; int m_configured;
    int IsPlayerCheatOn(int cheatBit) const;
};
int EGlobal::IsPlayerCheatOn(int cheatBit) const {
    if (m_configured) return 1;
    int r = 0;
    if ((m_cheats >> cheatBit) & 1) r = 1;
    return r;
}
