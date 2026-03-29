// 0x80149138 (36 bytes)
// StackElem::SetTreeID(short)
// DOL: cmpwi r4,-1; bne +12; sth r4,0(r3); blr
//       lhz r0,0(r3); rlwinm r0,r0,0,0,16 (=r0&0xFFFF8000); or r0,r4,r0; sth r0,0(r3); blr
// When r4==-1: store directly; else keep bit15 of old, OR in new value

class StackElem {
public:
    unsigned short m_treeID;  // offset 0
    void SetTreeID(short id);
};

void StackElem::SetTreeID(short id) {
    if (id == -1) {
        m_treeID = (unsigned short)id;
    } else {
        unsigned int old = m_treeID;
        old &= ~0x7FFFU;
        m_treeID = (unsigned short)(id | (short)old);
    }
}
