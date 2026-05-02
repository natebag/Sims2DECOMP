/* EString2::GetLength(void) const @ 0x802D4780 (36 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_GL {
    wchar_t_u *m_str;
    int GetLength() const;
    static int StrLenC16(wchar_t_u *s);
};

int EString2_GL::GetLength() const {
    return StrLenC16(m_str);
}
