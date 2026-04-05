/* MODTarget::ShowMood(void) at 0x801C9AE4 (12B) */

struct MODTarget {
    char pad[0x90];
    int m_moodShown;

    void ShowMood(void);
};

void MODTarget::ShowMood(void) {
    m_moodShown = 1;
}
