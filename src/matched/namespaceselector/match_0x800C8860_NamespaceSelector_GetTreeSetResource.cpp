// 0x800C8860 NamespaceSelector::GetTreeSetResource (8B)
struct NamespaceSelector {
    char pad[48];
    void* m_treeSetResource;
    void* GetTreeSetResource();
};

void* NamespaceSelector::GetTreeSetResource() { return m_treeSetResource; }
