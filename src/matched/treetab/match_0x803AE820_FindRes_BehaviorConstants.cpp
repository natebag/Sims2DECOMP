// 0x803AE820 BehaviorConstants * FindRes<BehaviorConstants>(BehaviorConstants *, BehaviorConstants *, int) (96B)
// FLAGS: -fno-schedule-insns

struct BehaviorConstants {
    int m_id;
    int field_4;
    int field_8;
    int field_c;
};

BehaviorConstants *FindRes(BehaviorConstants *lo, BehaviorConstants *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    BehaviorConstants *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
