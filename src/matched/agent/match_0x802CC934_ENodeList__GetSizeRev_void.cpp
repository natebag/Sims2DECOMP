// 0x802CC934 ENodeList::GetSizeRev(void) (48 B)

struct ENode {
    char pad_0000[0x4];
    ENode* m_prev;
};

struct ENodeList {
    char pad_0000[0x4];
    ENode* m_tail;

    int GetSizeRev();
};

int ENodeList::GetSizeRev() {
    ENode* p = m_tail;
    int count = 0;
    // DOL materializes the loop condition into a register (li 1 / cmpwi /
    // li 0 / cmpwi 0 / bne) rather than a single direct cmpwi+branch.
    int more;
    while ((more = (p != 0)) != 0) {
        p = p->m_prev;
        count++;
    }
    return count;
}
