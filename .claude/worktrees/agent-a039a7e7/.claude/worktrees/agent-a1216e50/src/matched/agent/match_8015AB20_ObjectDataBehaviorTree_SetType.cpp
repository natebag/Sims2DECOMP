// 0x8015AB20 (12 bytes)
// ObjectDataBehaviorTree::SetType(unsigned char)
// lwz r9, 84(r3); stb r4, 4(r9); blr
class Behavior;

struct BehaviorTreeData {
    char m_pad[4];
    unsigned char m_type;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    void SetType(unsigned char type);
};

void ObjectDataBehaviorTree::SetType(unsigned char type) {
    m_data->m_type = type;
}
