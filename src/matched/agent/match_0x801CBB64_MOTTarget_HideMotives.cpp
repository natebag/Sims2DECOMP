/* MOTTarget::HideMotives(void) at 0x801CBB64 (16B) */

struct MOTTarget {
    char pad[0x94];
    int m_motivesShown;
    char pad2[0x160 - 0x94 - 4];
    int m_motivesActive;

    void HideMotives(void);
};

void MOTTarget::HideMotives(void) {
    m_motivesActive = 0;
    m_motivesShown = 0;
}
