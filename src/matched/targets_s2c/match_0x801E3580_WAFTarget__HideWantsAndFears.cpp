/* WAFTarget::HideWantsAndFears(void) at 0x801E3580 (16B) */

struct WAFTarget {
    char pad[0x90];
    int m_field90;
    char pad2[0x08];
    int m_field9C;

    void HideWantsAndFears(void);
};

void WAFTarget::HideWantsAndFears(void) {
    m_field90 = 0;
    m_field9C = 0;
}
