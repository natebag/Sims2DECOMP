/* EString2::MakeLower(void) @ 0x802D47DC (52 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_ML {
    wchar_t_u *m_str;
    EString2_ML *MakeLower();
};

EString2_ML *EString2_ML::MakeLower() {
    wchar_t_u *p = m_str;
    wchar_t_u c = *p;
    if (!c) return this;
    do {
        if ((wchar_t_u)(c - 65) <= 25)
            *p = (wchar_t_u)(c + 32);
        c = *++p;
    } while (c);
    return this;
}
