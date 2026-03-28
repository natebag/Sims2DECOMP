/* operator>>(EStream &, EString2 &) - 0x802D53AC (72 bytes) */

typedef unsigned short wchar_t_u;

struct EStream {
    void ReadU16String(wchar_t_u *, int);
};

struct EString2 {
    EString2 &operator_assign(wchar_t_u *);
};

EStream &operator_shr_EStream_EString2(EStream &s, EString2 &str)
{
    wchar_t_u buf[4096];
    s.ReadU16String(buf, 4096);
    str.operator_assign(buf);
    return s;
}
