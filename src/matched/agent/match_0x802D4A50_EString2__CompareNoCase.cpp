// 0x802D4A50 EString2::CompareNoCase(EString2 const &) (116B)
typedef unsigned short wchar_t_u;

struct EString2_CNC {
    wchar_t_u *m_str;
    int CompareNoCase(wchar_t_u *s) const;
};

int EString2_CNC::CompareNoCase(wchar_t_u *s) const {
    wchar_t_u *p = m_str;
    do {
        unsigned int mc = *p;
        if (mc - 'a' <= 25u) mc = (mc - 32) & 0xFFFF;
        unsigned int sc = *s;
        if (sc - 'a' <= 25u) sc = (sc - 32) & 0xFFFF;
        if (mc < sc) return -1;
        if (mc > sc) return 1;
        ++p;
        ++s;
    } while (*p || *s);
    return 0;
}
