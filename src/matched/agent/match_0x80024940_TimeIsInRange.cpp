// TimeIsInRange(int, int, int) at 0x80024940 (76 bytes)
// Returns 1 if t is in [start, end], handling wraparound when start > end.

int TimeIsInRange(int t, int start, int end) {
    if (start > end) {
        int v = 0;
        if (t >= start) v = 1;
        else if (t <= end) v = 1;
        return v;
    }
    int v = 0;
    if (t >= start) v = (t <= end);
    return v;
}
