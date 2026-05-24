// FLAGS: -fno-schedule-insns
// 0x80196364 CASTarget::IsViewingCAR(void) (20B)
// lwz r3,0x104(r3); xori r3,r3,3; subfic r0,r3,0; adde r3,r0,r3; blr
struct CASTarget {
    char pad[0x104];
    int m_viewMode;  // offset 0x104
    int IsViewingCAR() const;
};
int CASTarget::IsViewingCAR() const {
    return m_viewMode == 3;
}
