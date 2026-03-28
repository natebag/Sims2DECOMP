struct AptCIH {
    char pad[0x48];
    AptCIH* m_parent;

    int getParentCount();
};

int AptCIH::getParentCount() {
    int count = 0;
    AptCIH* p = m_parent;
    while (p != 0) {
        count++;
        p = p->m_parent;
    }
    return count;
}
