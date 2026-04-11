/* ResourceBehaviorTree::AddRef(void) - 0x8015B268 - 20 bytes */

struct ResourceBehaviorTree {
    char _pad[100];
    int m_refCount;

    int AddRef();
};

int ResourceBehaviorTree::AddRef() {
    return ++m_refCount;
}
