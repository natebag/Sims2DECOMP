// 0x801BE548 K2YTarget::IsModeValid(void) (36B)
// Range check 2..8 with early-return for mode>8.

extern int gv_K2YTarget_GetModevoid;

int gf_K2YTarget_IsModeValidvoid() {
    int m = gv_K2YTarget_GetModevoid;
    if (m > 8) return 0;
    return (m >= 2) ? 1 : 0;
}
