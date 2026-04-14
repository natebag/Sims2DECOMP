/* ResourceBehaviorTree::ResourceBehaviorTree(void) - 0x8015AC58 - 72 bytes */

struct ObjectDataBehaviorTree {
    char _data[96];
    ObjectDataBehaviorTree();
};

struct ResourceBehaviorTree : public ObjectDataBehaviorTree {
    int m_refCount;   // offset 96 (first declared, lower offset)
    int m_field100;   // offset 100 (second declared, higher offset)
    ResourceBehaviorTree();
};

extern void *__vt__ResourceBehaviorTree[];

ResourceBehaviorTree::ResourceBehaviorTree() : ObjectDataBehaviorTree() {
    m_field100 = 0;
    *(void ***)this = __vt__ResourceBehaviorTree;
    m_refCount = 0;
}
