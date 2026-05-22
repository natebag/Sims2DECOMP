// 0x803AD650 SlotDescList * FindRes<SlotDescList>(SlotDescList *, SlotDescList *, int) (96B)
// FLAGS: -fno-schedule-insns

struct SlotDescList {
    int field_0;
    int m_id;
};

SlotDescList *FindRes(SlotDescList *lo, SlotDescList *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    SlotDescList *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
