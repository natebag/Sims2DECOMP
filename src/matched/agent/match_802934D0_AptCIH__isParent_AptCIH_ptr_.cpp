struct AptCIH {
    char pad[0x48];
    AptCIH* m_parent;

    int isParent(AptCIH* target);
};

int AptCIH::isParent(AptCIH* target) {
    AptCIH* p = m_parent;
    while (p != 0) {
        if (target == p)
            return 1;
        p = p->m_parent;
    }
    return 0;
}
