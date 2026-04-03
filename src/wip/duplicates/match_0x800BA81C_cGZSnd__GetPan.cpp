/* cGZSnd::GetPan(void) at 0x800BA81C (8B) */

struct cGZSnd {
    char pad[0x24];
    int m_pan;

    int GetPan(void);
};

int cGZSnd::GetPan(void) {
    return m_pan;
}
