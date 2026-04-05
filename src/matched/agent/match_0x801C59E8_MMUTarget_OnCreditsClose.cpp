/* MMUTarget::OnCreditsClose(void) at 0x801C59E8 (12B) */
/* li r0, 1; stw r0, 0xFC(r3); blr */

struct MMUTarget {
    char _pad[0xFC];
    int m_onCreditsClose;
    void OnCreditsClose(void);
};

void MMUTarget::OnCreditsClose(void) {
    m_onCreditsClose = 1;
}
