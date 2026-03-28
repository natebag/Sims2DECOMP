// 0x8015AC1C (12 bytes)
// ObjectDataBehaviorTree::GetTreeVersion(void) const
// lwz r9, 84(r3); lbz r3, 11(r9); blr
class Behavior;

struct BehaviorTreeData {
    char m_pad[11];
    unsigned char m_treeVersion;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    unsigned char GetTreeVersion() const;
};

unsigned char ObjectDataBehaviorTree::GetTreeVersion() const {
    return m_data->m_treeVersion;
}
