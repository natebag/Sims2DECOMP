// 0x8015AC10 (12 bytes)
// ObjectDataBehaviorTree::SetNumLocals(unsigned char)
// lwz r9, 84(r3); stb r4, 6(r9); blr
class Behavior;

struct BehaviorTreeData {
    char m_pad[6];
    unsigned char m_numLocals;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    void SetNumLocals(unsigned char numLocals);
};

void ObjectDataBehaviorTree::SetNumLocals(unsigned char numLocals) {
    m_data->m_numLocals = numLocals;
}
