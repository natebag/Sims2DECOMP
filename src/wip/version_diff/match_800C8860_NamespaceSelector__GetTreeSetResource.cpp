/* NamespaceSelector::GetTreeSetResource(void) - 0x800C8860 (8 bytes) */

struct NamespaceSelector {
    char m_pad[0x30];
    void *m_treeSetResource;

    void *GetTreeSetResource(void);
};

void *NamespaceSelector::GetTreeSetResource(void) {
    return m_treeSetResource;
}
