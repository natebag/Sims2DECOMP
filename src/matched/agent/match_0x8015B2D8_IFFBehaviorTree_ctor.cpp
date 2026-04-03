/* IFFBehaviorTree::IFFBehaviorTree(void) - 0x8015B2D8 - 68 bytes */

struct ObjectDataBehaviorTree {
    char _data[96];
    ObjectDataBehaviorTree();
};

struct IFFBehaviorTree : public ObjectDataBehaviorTree {
    int m_refCount;
    IFFBehaviorTree();
};

extern void *__vt__IFFBehaviorTree[];

IFFBehaviorTree::IFFBehaviorTree() : ObjectDataBehaviorTree() {
    m_refCount = 0;
    *(void ***)this = __vt__IFFBehaviorTree;
}
