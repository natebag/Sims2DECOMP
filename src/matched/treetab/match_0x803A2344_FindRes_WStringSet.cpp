// 0x803A2344 WStringSet * FindRes<WStringSet>(WStringSet *, WStringSet *, int) (112B)
// FLAGS: -fno-schedule-insns

struct WStringSet {
    int field_0;
    int field_4;
    short m_id;
    short pad;
};

WStringSet *FindRes(WStringSet *lo, WStringSet *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    WStringSet *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
