// 0x8015B37C IFFBehaviorTree::~IFFBehaviorTree() (104B)

class ObjectDataBehaviorTree {
public:
    virtual ~ObjectDataBehaviorTree();
};

class IFFBehaviorTree : public ObjectDataBehaviorTree {
public:
    char pad4[4];
    int m_8;
    char padC[0x48];
    char* m_54;
    ~IFFBehaviorTree();
};

IFFBehaviorTree::~IFFBehaviorTree() {
    if (m_8 != 0) {
        if (m_54 != 0) {
            delete[] m_54;
        }
        m_54 = 0;
    }
}
