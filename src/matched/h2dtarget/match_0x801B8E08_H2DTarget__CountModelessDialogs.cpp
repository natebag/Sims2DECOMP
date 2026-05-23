/* H2DTarget::CountModelessDialogs(void) at 0x801B8E08 (52B) */

struct MDITarget_CMd {
    int CountModelessDialogs();
};

struct H2DTarget_CMd {
    char m_pad[200];
    MDITarget_CMd* m_mdi;
    int CountModelessDialogs();
};

int H2DTarget_CMd::CountModelessDialogs() {
    MDITarget_CMd* p = m_mdi;
    if (!p) return 0;
    return p->CountModelessDialogs();
}
