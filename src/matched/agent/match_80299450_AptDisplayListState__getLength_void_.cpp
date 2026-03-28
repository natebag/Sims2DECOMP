struct AptCIH_Node {
    char pad[0x54];
    AptCIH_Node* m_next;
};

struct AptDisplayListState {
    AptCIH_Node* m_head;

    int getLength();
};

int AptDisplayListState::getLength() {
    AptCIH_Node* p = m_head;
    int count = 0;
    while (p != 0) {
        count++;
        p = p->m_next;
    }
    return count;
}
