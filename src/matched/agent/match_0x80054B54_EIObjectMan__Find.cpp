// EIObjectMan::Find(ISimInstance *) at 0x80054B54 (52 bytes)
// Linked-list scan: returns true iff any node has m_obj == arg.

class ISimInstance;

struct EIObjectMan_F_Node {
    char _pad[16];
    EIObjectMan_F_Node* m_next;   // 16
    char _pad2[8];
    ISimInstance* m_obj;          // 28
};

struct EIObjectMan_F {
    char _pad[4];
    EIObjectMan_F_Node* m_head;   // 4
    bool Find(ISimInstance* obj);
};

bool EIObjectMan_F::Find(ISimInstance* obj) {
    EIObjectMan_F_Node* n = m_head;
    while (n) {
        if (obj == n->m_obj) return true;
        n = n->m_next;
    }
    return false;
}
