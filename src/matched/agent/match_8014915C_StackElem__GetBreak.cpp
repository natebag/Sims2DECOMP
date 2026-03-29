// 0x8014915C (32 bytes)
// StackElem::GetBreak(void) const
// DOL: lha r0,0(r3); li r3,0; cmpwi r0,-1; beqlr; andi. r9,r0,0x8000; beqlr; li r3,1; blr

class StackElem {
public:
    short m_treeID;
    int GetBreak() const;
};

static int s_getbreak_zero = 0;

int StackElem::GetBreak() const {
    int v = m_treeID;
    int r = s_getbreak_zero;
    if (v == -1) return r;
    if (!(v & 0x8000)) return r;
    return 1;
}
