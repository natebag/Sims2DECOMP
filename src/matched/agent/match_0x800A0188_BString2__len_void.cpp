// FLAGS: -fno-schedule-insns
// 0x800A0188 BString2::len(void) (12B)
// lwz r3,0(r3); addi r3,r3,4; blr
struct BString2 {
    int m_len;  // offset 0
    int len() const;
};
int BString2::len() const {
    return m_len + 4;
}
