extern int __vt_NodeAllocRefillHelper[];

void NodeAllocRefillFunc(void *);

struct NodeAllocRefillHelper {
    char pad_00[0x04];
    int* m_vtable;

    void RefillInit(int flag);
};

void NodeAllocRefillHelper::RefillInit(int flag) {
    m_vtable = __vt_NodeAllocRefillHelper;
    if (flag & 1) {
        NodeAllocRefillFunc(this);
    }
}
