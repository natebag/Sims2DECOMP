// 0x8039E4FC SpriteIdToResIdNode * FindRes<SpriteIdToResIdNode>(SpriteIdToResIdNode *, SpriteIdToResIdNode *, int) (112B)
// FLAGS: -fno-schedule-insns

struct SpriteIdToResIdNode {
    int m_id;
    int field_4;
    int field_8;
};

SpriteIdToResIdNode *FindRes(SpriteIdToResIdNode *lo, SpriteIdToResIdNode *hi, int key)
{
    int n = hi - lo;
    if (n <= 0) return 0;
    if (n == 1) {
        if (lo->m_id == key) return lo;
        return 0;
    }
    SpriteIdToResIdNode *mid = &lo[n / 2];
    int diff = key - mid->m_id;
    if (diff == 0) return mid;
    if (diff > 0) return FindRes(mid + 1, hi, key);
    return FindRes(lo, mid, key);
}
