// 0x80149118 (32 bytes)
// StackElem::GetTreeID(void) const
// lhz r3, 0(r3); extsh r0, r3; cmpwi r0, -1; beq ret_neg1; rlwinm r3,r3,0,17,31; blr
// li r3, -1; blr
// Returns: -1 if stored==0xFFFF, else (stored & 0x7FFF)

class StackElem {
public:
    unsigned short m_treeID;  // offset 0 — bit15=breakFlag, bits14:0=treeID (0x7FFF=none)
    int GetTreeID() const;
};

int StackElem::GetTreeID() const {
    short v = (short)m_treeID;
    if (v == -1)
        return -1;
    return (int)(m_treeID & 0x7FFF);
}
