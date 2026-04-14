/* MDITarget::ShowModelessDialog(void) at 0x801C3C84 (12B) */

struct MDITarget {
    char pad[0x9C];
    int m_dialogShown;

    void ShowModelessDialog(void);
};

void MDITarget::ShowModelessDialog(void) {
    m_dialogShown = 1;
}
