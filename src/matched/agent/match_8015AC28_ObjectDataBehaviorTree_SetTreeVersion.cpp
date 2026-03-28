// 0x8015AC28 (12 bytes)
// ObjectDataBehaviorTree::SetTreeVersion(unsigned char)
// lwz r9, 84(r3); stw r4, 8(r9); blr
class Behavior;

struct BehaviorTreeData {
    char m_pad[8];
    int m_treeVersion;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    void SetTreeVersion(unsigned char ver);
};

void ObjectDataBehaviorTree::SetTreeVersion(unsigned char ver) {
    m_data->m_treeVersion = ver;
}
