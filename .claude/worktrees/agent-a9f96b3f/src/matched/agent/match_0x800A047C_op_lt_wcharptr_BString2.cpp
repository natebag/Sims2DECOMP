/* operator<(unsigned wchar_t *, BString2 &) - 0x800A047C (64 bytes) */

typedef unsigned short wchar_t_u;

struct BString2 {
    int compare(wchar_t_u *, unsigned int) const;
};

int operator_lt_wcharptr_BString2(wchar_t_u *lhs, BString2 &rhs)
{
    int r = rhs.compare(lhs, 0);
    return r > 0;
}
