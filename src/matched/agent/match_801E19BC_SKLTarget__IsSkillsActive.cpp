class SKLTarget {
public:
    char pad[0x88];
    int m_isSkillsActive;
    int IsSkillsActive(void);
};

int SKLTarget::IsSkillsActive(void) {
    return m_isSkillsActive;
}
