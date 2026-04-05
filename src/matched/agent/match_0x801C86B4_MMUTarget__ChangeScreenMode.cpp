/* MMUTarget::ChangeScreenMode(MMUTarget::MMU_MODE) at 0x801C86B4 (16B) */

struct MMUTarget {
    typedef int MMU_MODE;

    char pad[0x8C];
    MMU_MODE m_mode;
    MMU_MODE m_prevMode;

    void ChangeScreenMode(MMU_MODE mode);
};

void MMUTarget::ChangeScreenMode(MMU_MODE mode) {
    MMU_MODE old = m_mode;
    m_mode = mode;
    m_prevMode = old;
}
