// 0x803AE1F0 FindRes<TreeTableEntry> (112b)
// FLAGS: -fno-schedule-insns

struct TreeTableEntry {
    char _pad[20];
    short m_id;
    char _pad2[14];
};

TreeTableEntry *FindRes(TreeTableEntry *lo, TreeTableEntry *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    TreeTableEntry *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
