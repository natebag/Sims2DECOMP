struct EGlobal {
    char pad1[156]; unsigned short m_cheats;
    char pad2[866]; int m_configured;
    int GetPlayerCheats() const;
};
int EGlobal::GetPlayerCheats() const {
    if (m_configured) return 0xFFFF;
    return m_cheats;
}
