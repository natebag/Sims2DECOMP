/* EString2::Empty(void) @ 0x802D48D0 (56 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_E {
    wchar_t_u *m_str;
    void Deallocate(wchar_t_u *p);
    void SetToNull();
    void Empty();
};

void EString2_E::Empty() {
    wchar_t_u *old = m_str;
    Deallocate(old);
    SetToNull();
}
