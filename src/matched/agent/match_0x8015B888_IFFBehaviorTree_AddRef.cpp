/* IFFBehaviorTree::AddRef(void) - 0x8015B888 - 20 bytes */

struct IFFBehaviorTree {
    char _pad[96];
    int m_refCount;

    int AddRef();
};

int IFFBehaviorTree::AddRef() {
    return ++m_refCount;
}
