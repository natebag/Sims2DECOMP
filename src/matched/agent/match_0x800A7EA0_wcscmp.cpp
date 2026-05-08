// 0x800A7EA0 wcscmp(unsigned short*, unsigned short*) (60B)

int wcscmp(unsigned short *a, unsigned short *b) {
    unsigned short lhs;
    unsigned short rhs;
    int diff;

    do {
        lhs = *a;
        rhs = *b;
        diff = lhs - rhs;
        if (diff != 0) {
            break;
        }
        a++;
        if (lhs == 0) {
            break;
        }
        b++;
    } while (rhs != 0);

    return diff;
}
