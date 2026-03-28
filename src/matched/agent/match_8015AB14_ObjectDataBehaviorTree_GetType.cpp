// 0x8015AB14 (12 bytes)
// ObjectDataBehaviorTree::GetType(void) const
// lwz r9, 84(r3); lbz r3, 4(r9); blr
struct BehaviorTreeData {
    char m_pad[4];
    unsigned char m_type;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    unsigned char GetType() const;
};

unsigned char ObjectDataBehaviorTree::GetType() const {
    return m_data->m_type;
}
