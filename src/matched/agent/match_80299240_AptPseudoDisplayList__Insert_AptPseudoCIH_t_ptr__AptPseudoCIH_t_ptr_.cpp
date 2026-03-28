struct AptPseudoCIH_t {
    char pad[0x08];
    AptPseudoCIH_t* m_prev;
    AptPseudoCIH_t* m_next;
};

struct AptPseudoDisplayList {
    void Insert(AptPseudoCIH_t* after, AptPseudoCIH_t* node);
};

void AptPseudoDisplayList::Insert(AptPseudoCIH_t* after, AptPseudoCIH_t* node) {
    AptPseudoCIH_t* oldPrev = after->m_prev;
    node->m_next = after;
    node->m_prev = oldPrev;
    if (oldPrev != 0) {
        oldPrev->m_next = node;
    }
    AptPseudoCIH_t* next = node->m_next;
    next->m_prev = node;
}
