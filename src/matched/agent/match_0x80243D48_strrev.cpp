void strrev(char *s)
{
    int hi = 0;
    while (s[hi] != 0) {
        hi++;
    }

    int lo = 0;
    hi = hi - 1;
    while (lo < hi) {
        char a = s[hi];
        char b = s[lo];
        s[lo] = a;
        s[hi] = b;
        lo++;
        hi--;
    }
}
