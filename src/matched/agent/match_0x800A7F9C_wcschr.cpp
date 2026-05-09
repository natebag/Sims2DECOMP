// 0x800A7F9C (56B) wcschr
// Find wide-char `c` in `str`; return pointer-to-char or NULL.
// Uses lhzu pre-increment loop and final null-or-pointer ternary.

unsigned short* wcschr(unsigned short* str, unsigned short c)
{
    unsigned short v = *str;
    while (v != 0 && v != c) {
        v = *++str;
    }
    unsigned short* ret = 0;
    if (*str != 0) {
        ret = str;
    }
    return ret;
}
