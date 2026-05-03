/* EString2::MakeUpper(void) @ 0x802D47A4 (56 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_MU {
    wchar_t_u *m_str;
    EString2_MU *MakeUpper();
};

EString2_MU *EString2_MU::MakeUpper() {
    wchar_t_u *p = m_str;
    unsigned int c = *p;
    if (!c) return this;
    do {
        if ((c - 97) <= 25u) {
            c += 65504;
            *p = c;
        }
        c = *++p;
    } while (c);
    return this;
}
