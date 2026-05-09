// MATCH: 0x801BE548 K2YTarget::IsModeValid(void) | Size: 36 bytes
// FLAGS: -O2 -g0

extern int g_k2yMode;

struct K2YTarget {
    int IsModeValid();
};

int K2YTarget::IsModeValid() {
    int mode = g_k2yMode;
    int r = 0;
    if (mode > 8) return r;
    r = (mode == 2) || (mode > 2);
    return r;
}
