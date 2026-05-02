/* operator<<(EStream &, EString2 &) @ 0x802D5378 (52 bytes) */

typedef unsigned short wchar_t_u;

struct EStream_WU {
    void WriteU16String(wchar_t_u *s);
};

struct EString2_SHL {
    wchar_t_u *m_str;
};

EStream_WU& operator<<(EStream_WU& es, EString2_SHL& str) {
    es.WriteU16String(str.m_str);
    return es;
}
