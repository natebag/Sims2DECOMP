// 0x803AE8FC ObjDefinition * * FindResIndirect<ObjDefinition *>(ObjDefinition * *, ObjDefinition * *, int) (104B)
// FLAGS: -fno-schedule-insns

struct ObjDefinition {
    char _pad[0xbc];
    short m_id;
};

ObjDefinition **FindResIndirect(ObjDefinition **lo, ObjDefinition **hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if ((*lo)->m_id == key) return lo;
        return 0;
    }
    ObjDefinition **mid = &lo[n / 2];
    int diff = key - (*mid)->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindResIndirect(mid + 1, hi, key);
    return FindResIndirect(lo, mid, key);
}
