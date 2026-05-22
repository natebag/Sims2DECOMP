// 0x803ABB7C PropRefTable * FindRes<PropRefTable>(PropRefTable *, PropRefTable *, int) (96B)
// FLAGS: -fno-schedule-insns

struct PropRefTable {
    int field_0;
    short m_id;
    short pad;
};

PropRefTable *FindRes(PropRefTable *lo, PropRefTable *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    PropRefTable *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
