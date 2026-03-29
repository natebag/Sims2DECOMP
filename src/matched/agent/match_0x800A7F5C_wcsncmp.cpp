int wcsncmp(unsigned short *a, unsigned short *b, int count) {
    int i = 0;
    unsigned short lhs;
    unsigned short rhs;
    int diff;

    do {
        i++;
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
        if (rhs == 0) {
            break;
        }
    } while (i < count);

    return diff;
}
