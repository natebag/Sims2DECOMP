// 0x8014917C (48 bytes)
// StackElem::SetBreak(bool)
// DOL: lhz r9,0(r3); extsh r0,r9; cmpwi r0,-1; beqlr
//       cmpwi r4,0; beq +16
//       ori r0,r9,0x8000; sth r0,0(r3); blr
//       rlwinm r0,r9,0,17,31; sth r0,0(r3); blr
// If stored==-1: do nothing. If param: set bit15. Else: clear bit15.

class StackElem {
public:
    unsigned short m_treeID;
    void SetBreak(int enable);
};

int StackElem__SetBreak_zero = 0;

void StackElem::SetBreak(int enable) {
    int v = (short)m_treeID;
    if (v == -1) return;
    if (enable) {
        m_treeID = (unsigned short)(m_treeID | 0x8000);
    } else {
        m_treeID = (unsigned short)(m_treeID & 0x7FFF);
    }
}
