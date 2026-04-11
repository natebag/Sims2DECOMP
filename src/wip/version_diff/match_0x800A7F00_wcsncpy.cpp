unsigned short *wcsncpy(unsigned short *dst, unsigned short *src, int count) {
    unsigned short *out = dst;
    unsigned short ch = *src;

    if (ch != 0) {
        if (count != 0) {
            do {
                *dst = ch;
                count--;
                ch = *++src;
                dst++;
                if (ch == 0) {
                    break;
                }
            } while (count != 0);
        }
    }

    if (count != 0) {
        do {
            *dst = 0;
            count--;
            dst++;
        } while (count != 0);
    }

    return out;
}
