// FLAGS: -fno-schedule-insns
// 0x80327E38 EResourceMap::IsEmpty(void) (16B)
// lwz r3,0x4(r3); subfic r0,r3,0; adde r3,r0,r3; blr — m_size == 0
struct EResourceMap {
    char pad[4];
    int m_size;  // offset 4
    int IsEmpty() const;
};
int EResourceMap::IsEmpty() const {
    return m_size == 0;
}
