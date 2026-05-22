// 0x803A869C ObjFnData * FindRes<ObjFnData>(ObjFnData *, ObjFnData *, int) (112B)
// FLAGS: -fno-schedule-insns

struct ObjFnData {
    int m_id;
    char _pad[120];
};

ObjFnData *FindRes(ObjFnData *lo, ObjFnData *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    ObjFnData *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
