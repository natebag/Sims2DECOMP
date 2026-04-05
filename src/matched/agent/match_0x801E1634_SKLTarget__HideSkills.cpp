/* SKLTarget::HideSkills(void) at 0x801E1634 (16B) */

struct SKLTarget {
    char pad[0x90];
    int m_field90;
    char pad2[0x08];
    int m_field9C;

    void HideSkills(void);
};

void SKLTarget::HideSkills(void) {
    m_field90 = 0;
    m_field9C = 0;
}
