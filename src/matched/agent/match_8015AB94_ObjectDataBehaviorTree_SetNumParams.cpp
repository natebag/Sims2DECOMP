// 0x8015AB94 (12 bytes)
// ObjectDataBehaviorTree::SetNumParams(unsigned char)
// lwz r9, 84(r3); stb r4, 5(r9); blr
struct BehaviorTreeData {
    char m_pad[5];
    unsigned char m_numParams;
};

class ObjectDataBehaviorTree {
public:
    char m_pad[84];
    BehaviorTreeData* m_data;
    void SetNumParams(unsigned char numParams);
};

void ObjectDataBehaviorTree::SetNumParams(unsigned char numParams) {
    m_data->m_numParams = numParams;
}
