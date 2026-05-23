// 0x80072CBC SimModel::UpdateReweld(bool) (128B)

struct Node {
    char pad[288];
    void* m_data;  // offset 288
};

struct SimModel {
    char pad[4];
    unsigned int m_f4;        // offset 4
    char pad2[100];
    Node* m_node;              // offset 108
    void RebuildModified(void);
    void UpdateReweld(bool arg);
};

extern "C" void SM_DoCall(void* data);                 // 0x8031a34c
extern "C" void SM_ClearArea(void* base, int x);        // 0x80074ca8
extern "C" void SM_DoFinal(SimModel* self);             // 0x800708f4

void SimModel::UpdateReweld(bool arg) {
    RebuildModified();
    Node* n = m_node;
    if (n == 0) return;
    void* d = n->m_data;
    if (d == 0) return;
    if ((m_f4 & 4) == 0) {
        SM_DoCall(d);
        m_f4 |= 2;
    }
    if (arg) {
        SM_ClearArea((char*)this + 104, 0);
        SM_DoFinal(this);
    }
}
