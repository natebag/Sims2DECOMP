// 0x80282774 (72B) AptCharacterAnimation::IsImport(int)

struct AptCharacterAnimation {
    char pad[0x20];
    int m_count;
    void* m_base;

    int IsImport(int target);
};

int AptCharacterAnimation::IsImport(int target) {
    for (int i = 0; i < m_count; i++) {
        int* p = (int*)((char*)m_base + 8 + i * 16);
        if (*p == target) {
            return i;
        }
    }
    return -1;
}
