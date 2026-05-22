// 0x803A22D4 AStringSet * FindRes<AStringSet>(AStringSet *, AStringSet *, int) (112B)
// FLAGS: -fno-schedule-insns

struct AStringSet {
    int field_0;
    int field_4;
    short m_id;
    short pad;
};

AStringSet *FindRes(AStringSet *lo, AStringSet *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    AStringSet *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
