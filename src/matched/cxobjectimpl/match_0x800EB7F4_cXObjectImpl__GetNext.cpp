// 0x800EB7F4 cXObjectImpl::GetNext (24B)

struct Node_GN { char pad[4]; void* next; };

struct cXObj_GN {
    char pad[0x5C];
    Node_GN* m_ptr;
    void* GetNext();
};

void* cXObj_GN::GetNext() {
    Node_GN* p = m_ptr;
    void* result = 0;
    if (p != 0) result = p->next;
    return result;
}
