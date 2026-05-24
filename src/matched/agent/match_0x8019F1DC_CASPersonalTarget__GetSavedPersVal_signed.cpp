// FLAGS: -fno-schedule-insns
// 0x8019F1DC CASPersonalTarget::GetSavedPersVal(signed) (16B)
// addi r3,r3,140; lbzx r3,r3,r4; extsb r3,r3; blr — load byte from array[idx], sign-extend
struct CASPersonalTarget {
    char pad[140];
    signed char m_savedPers[8];
    signed char GetSavedPersVal(int idx) const;
};
signed char CASPersonalTarget::GetSavedPersVal(int idx) const {
    return m_savedPers[idx];
}
