class SKLTarget {
public:
    char pad[0x90];
    int m_showSkills;
    void ShowSkills(void);
};

void SKLTarget::ShowSkills(void) {
    m_showSkills = 1;
}
