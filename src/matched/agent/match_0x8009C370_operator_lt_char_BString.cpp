/* operator_lt_char_BString at 0x8009C370 (68B) */
// FLAGS: -fno-elide-constructors

extern int StrCompare(void *, int, int, int);

int operator_lt_char_BString(int ch, void *str) {
    int r = StrCompare(str, ch, 0, 1);
    if (r > 0) return 1;
    return 0;
}
