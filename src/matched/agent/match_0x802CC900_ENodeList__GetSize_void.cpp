// 0x802CC900 ENodeList::GetSize(void) (52 B)

struct ENode {
    char pad_0000[0x8];
    ENode* m_next;
};

struct ENodeList {
    ENode* m_head;

    int GetSize();
};

int ENodeList::GetSize() {
    ENode* p = m_head;
    int count = 0;
    // DOL materializes the loop condition into a register (li 1 / cmpwi /
    // li 0 / cmpwi 0 / bne) rather than a single direct cmpwi+branch.
    int more;
    while ((more = (p != 0)) != 0) {
        p = p->m_next;
        count++;
    }
    return count;
}
