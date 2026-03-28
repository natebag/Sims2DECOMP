/* FlashPiMenu::Kill(void) - 0x8003A7EC (12 bytes) */

struct FlashPiMenu {
    int m_field_00;
    int m_killed;

    void Kill();
};

void FlashPiMenu::Kill() {
    m_killed = 1;
}
