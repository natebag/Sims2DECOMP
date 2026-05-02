/* EString2::StrLenC16(unsigned wchar_t *) @ 0x802D4154 (56 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_SC16 {
    wchar_t_u *m_str;
    static int StrLenC16(wchar_t_u *s);
};

int EString2_SC16::StrLenC16(wchar_t_u *s) {
    if (!s) return 0;
    wchar_t_u c = *s;
    int i = 0;
    if (c) {
        do {
            c = *++s;
            i++;
        } while (c);
    }
    return i;
}
