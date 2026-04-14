/* operator_lt_wchar_BString2 at 0x800A04BC (68B) */
// FLAGS: -fno-elide-constructors

extern int StrCompare(void *, int, int, int);

int operator_lt_wchar_BString2(int ch, void *str) {
    int r = StrCompare(str, ch, 0, 1);
    if (r > 0) return 1;
    return 0;
}
