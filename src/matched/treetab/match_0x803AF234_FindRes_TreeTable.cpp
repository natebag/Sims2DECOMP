// 0x803AF234 TreeTable * FindRes<TreeTable>(TreeTable *, TreeTable *, int) (112B)
// FLAGS: -fno-schedule-insns

struct TreeTable {
    int field_0;
    short field_4;
    short m_id;
    int field_8;
};

TreeTable *FindRes(TreeTable *lo, TreeTable *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    TreeTable *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
