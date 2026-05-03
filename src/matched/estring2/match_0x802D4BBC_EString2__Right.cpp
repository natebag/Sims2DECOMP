// FLAGS: -fno-elide-constructors-only
/* EString2::Right(int) const @ 0x802D4BBC (84 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_R {
    wchar_t_u *m_str;
    EString2_R Right(int n) const;
    int GetLength() const;
    void MakeCopy(wchar_t_u *s);
    inline EString2_R(wchar_t_u *s) { MakeCopy(s); }
};

EString2_R EString2_R::Right(int n) const {
    return EString2_R(m_str + (GetLength() - n));
}
