typedef unsigned long size_t;

char *strrchr(const char *s, int c)
{
    char *found = 0;
    char ch = (char)c;

    while (*s != 0) {
        char sc = *s;
        if ((char)sc == ch) {
            found = (char *)s;
        }
        s++;
    }
    if ((char)*s == ch) {
        found = (char *)s;
    }
    return found;
}
