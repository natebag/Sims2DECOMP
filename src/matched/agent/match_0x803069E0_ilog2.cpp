// 0x803069E0 ilog2(unsigned int) (40B)
// Returns the number of left-shifts needed for pow2 to reach or exceed n.
// DOL uses dual-check form: guard at top + check at bottom = if+do-while.

int ilog2(unsigned int n) {
    unsigned int pow2 = 1;
    int exp = 0;
    if (pow2 < n) {
        do {
            pow2 <<= 1;
            exp++;
        } while (pow2 < n);
    }
    return exp;
}
