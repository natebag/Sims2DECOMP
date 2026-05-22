// 0x803A3610 FloatConstantsData * FindRes<FloatConstantsData>(FloatConstantsData *, FloatConstantsData *, int) (96B)
// FLAGS: -fno-schedule-insns

struct FloatConstantsData {
    int field_0;
    int m_id;
};

FloatConstantsData *FindRes(FloatConstantsData *lo, FloatConstantsData *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    FloatConstantsData *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
