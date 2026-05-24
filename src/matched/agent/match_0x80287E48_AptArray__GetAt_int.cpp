// FLAGS: -fno-schedule-insns
// 0x80287E48 AptArray::GetAt(int) (16B)
// lwz r9,0x24(r3); rlwinm r4,r4,2,0,29; lwzx r3,r4,r9; blr
struct AptArray {
    char pad[0x24];
    int* m_data;  // offset 0x24
    int GetAt(int idx) const;
};
int AptArray::GetAt(int idx) const {
    return m_data[idx];
}
