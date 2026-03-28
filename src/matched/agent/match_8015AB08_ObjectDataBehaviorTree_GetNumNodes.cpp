// 0x8015AB08 (12 bytes)
// ObjectDataBehaviorTree::GetNumNodes(void) const
// lwz r9, 84(r3); lha r3, 2(r9); blr
struct BehaviorTreeData {
    short m_structVersion;
    short m_numNodes;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    short GetNumNodes() const;
};

short ObjectDataBehaviorTree::GetNumNodes() const {
    return m_data->m_numNodes;
}
