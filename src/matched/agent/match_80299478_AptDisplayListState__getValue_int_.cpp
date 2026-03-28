struct AptCIH_Node {
    char pad[0x54];
    AptCIH_Node* m_next;
};

struct AptDisplayListState {
    AptCIH_Node* m_head;

    AptCIH_Node* getValue(int index);
};

AptCIH_Node* AptDisplayListState::getValue(int index) {
    AptCIH_Node* p = m_head;
    while (p != 0) {
        if (index == 0) return p;
        index--;
        p = p->m_next;
    }
    return 0;
}
