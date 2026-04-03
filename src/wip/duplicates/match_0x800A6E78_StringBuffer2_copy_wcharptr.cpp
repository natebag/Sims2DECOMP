/* StringBuffer2::copy(unsigned wchar_t *) - 0x800A6E78 (64 bytes) */

typedef unsigned short wchar_t_u;

struct StringBuffer2 {
    void erase();
    void append(wchar_t_u *, int);
    void copy(wchar_t_u *s);
};

void StringBuffer2::copy(wchar_t_u *s)
{
    erase();
    append(s, -1);
}
