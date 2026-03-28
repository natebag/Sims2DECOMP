// 0x8015AAFC (12 bytes)
// ObjectDataBehaviorTree::GetStructVersion(void) const
// lwz r9, 84(r3); lha r3, 0(r9); blr
class Behavior;

struct BehaviorTreeData {
    short m_structVersion;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    short GetStructVersion() const;
};

short ObjectDataBehaviorTree::GetStructVersion() const {
    return m_data->m_structVersion;
}
