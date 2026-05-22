// 0x803A2A4C AnimRefTable * FindRes<AnimRefTable>(AnimRefTable *, AnimRefTable *, int) (96B)
// FLAGS: -fno-schedule-insns

struct AnimRefTable {
    int field_0;
    short m_id;
    short pad;
};

AnimRefTable *FindRes(AnimRefTable *lo, AnimRefTable *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    AnimRefTable *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
