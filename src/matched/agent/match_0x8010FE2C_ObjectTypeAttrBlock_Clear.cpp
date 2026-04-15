// 0x8010FE2C (52B) ObjectTypeAttrBlock::Clear(void)

struct ObjectTypeAttrBlock {
    char pad[4];
    int m_count;
    short* m_arr;
    void Clear();
};

void ObjectTypeAttrBlock::Clear() {
    for (int i = 0; i < m_count; i++) {
        m_arr[i] = 0;
    }
}
