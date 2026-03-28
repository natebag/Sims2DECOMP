/* EString2::operator=(unsigned wchar_t *) - 0x802D4658 (64 bytes) */

typedef unsigned short wchar_t_u;

struct EString2 {
    wchar_t_u *m_str;

    void MakeCopy(wchar_t_u *);
    void Deallocate(wchar_t_u *);
    EString2 &op_assign(wchar_t_u *src);
};

EString2 &EString2::op_assign(wchar_t_u *src)
{
    wchar_t_u *old = m_str;
    MakeCopy(src);
    Deallocate(old);
    return *this;
}
