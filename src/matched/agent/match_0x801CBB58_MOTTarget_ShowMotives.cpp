/* MOTTarget::ShowMotives(void) at 0x801CBB58 (12B) */

struct MOTTarget {
    char pad[0x160];
    int m_motivesActive;

    void ShowMotives(void);
};

void MOTTarget::ShowMotives(void) {
    m_motivesActive = 1;
}
