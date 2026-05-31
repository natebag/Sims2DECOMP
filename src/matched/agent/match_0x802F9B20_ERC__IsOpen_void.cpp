// FLAGS: -fno-schedule-insns
// 0x802F9B20 ERC::IsOpen(void) (24B)
// lbz r0,0x18(3); li r3,1; cmplwi r0,0; bnelr; li r3,0  -- m_isOpen != 0
struct ERC {
    char pad[0x18];
    unsigned char m_isOpen; // 0x18
    int IsOpen();
};

int ERC::IsOpen() {
    if (m_isOpen) return 1;
    return 0;
}
