/* EIObjectMan::GetObjects(TNodeList<ISimInstance *> &) at 0x80054D08 (76B) */

struct ENodeList {
    void AddTail(unsigned int);
};

struct RBNode {
    char pad_00[0x10];
    RBNode *m_next;
    char pad_14[8];
    unsigned int m_data;
};

struct ERedBlackTree {
    RBNode *m_first;
};

struct EIObjectMan {
    int m_field_00;
    ERedBlackTree m_tree;

    void GetObjects(ENodeList *list);
};

void EIObjectMan::GetObjects(ENodeList *list) {
    RBNode *node = m_tree.m_first;
    while (node != 0) {
        list->AddTail(node->m_data);
        node = node->m_next;
    }
}
