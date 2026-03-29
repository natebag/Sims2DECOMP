unsigned short *wcscpy(unsigned short *dst, unsigned short *src) {
    unsigned short *out = dst;
    unsigned short ch = *src;

    if (ch != 0) {
        do {
            *out = ch;
            ch = *++src;
            out++;
        } while (ch != 0);
    }

    *out = 0;
    return dst;
}
