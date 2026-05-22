// 0x803069E0 ilog2(unsigned int) (40B)

int ilog2(unsigned int x) {
    int r = 0;
    unsigned int i = 1;
    while (i < x) {
        i <<= 1;
        r++;
    }
    return r;
}
