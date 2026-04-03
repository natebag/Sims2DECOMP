// 0x8015B818 (112 bytes) — VERIFIED MATCH
// IFFBehaviorTree::QueryInterface(unsigned int, void **)

struct QI_IFFBehaviorTree {
    int QueryInterface(unsigned int iid, void **output);
};

int QI_IFFBehaviorTree::QueryInterface(unsigned int iid, void **output) {
    if (!output) return 0;
    if (iid == 1 || iid == 0x2BEB2426) {
        int *vtable = *(int **)this;
        short delta = *(short *)((char *)vtable + 16);
        void (*func)(void *, unsigned int) = (void (*)(void *, unsigned int))*(void **)(((char *)vtable) + 20);
        func((char *)this + delta, iid);
        *output = this;
        return 1;
    }
    return 0;
}
