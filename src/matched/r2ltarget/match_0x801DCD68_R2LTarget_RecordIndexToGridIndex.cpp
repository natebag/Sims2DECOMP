// 0x801DCD68 R2LTarget::RecordIndexToGridIndex(int) (32B)

struct R2LTarget {
    char pad[164];
    int m_base;
    int RecordIndexToGridIndex(int idx);
};

int R2LTarget::RecordIndexToGridIndex(int idx) {
    unsigned int diff = idx - m_base * 6;
    if (diff > 6) return -1;
    return (int)diff;
}
