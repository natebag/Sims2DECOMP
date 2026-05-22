// 0x80231B90 ERLevel::AddInstancesFromList(TNodeList<EInstance*>&) (64B)

class EInstance;

template <typename T>
struct TNode {
    T m_value;
    char pad4[4];
    TNode<T>* m_next;
};

template <typename T>
struct TNodeList {
    TNode<T>* m_head;
};

class ERLevel {
public:
    char pad[0x2A2B8];
    EInstance* m_array[1];
    char pad2[0x2C2B8 - 0x2A2BC];
    int m_count;
    void AddInstancesFromList(TNodeList<EInstance*>& list);
};

void ERLevel::AddInstancesFromList(TNodeList<EInstance*>& list) {
    TNode<EInstance*>* node = list.m_head;
    if (node == 0) return;
    do {
        m_array[m_count] = node->m_value;
        ++m_count;
        node = node->m_next;
    } while (node != 0);
}
